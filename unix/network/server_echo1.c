// 多进程echo服务器
// 接收数据格式：message_length | message
// 发送数据格式：message_length | message

#include <stdio.h>          // printf, perror
#include <stdlib.h>         // exit
#include <string.h>         // bzero
#include <time.h>           // time
#include <unistd.h>         // fork, read, write, close
#include <sys/socket.h>     // socket, bind, listen, accept
#include <netinet/in.h>     // htonl, htons
#include <arpa/inet.h>      // inet_ntop
#include <libgen.h>         // basename

void sig_chld_handler(int signo) {
    pid_t pid;
    int stat;

    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
        printf("child %d terminated\n", pid);
    }
}

int readn(int fd, char* buff, int n) {
    int m = 0;
    while (m < n) {
        int len = read(fd, buff + m, n - m);
        if (len < 0) {
            perror("read failed.\n");
            return -1;
        }
        m += len;
    }

    return n;
}

int writen(int fd, char* buff, int n) {
    int m = 0;
    while (m < n) {
        int len = write(fd, buff + m, n - m);
        if (len < 0) {
            perror("write failed.\n");
            return -1;
        }
        m += len;
    }

    return n;
}

char* get_ip_port(struct sockaddr_in addr, char* buff, int len) {
    if (inet_ntop(AF_INET, &addr.sin_addr, buff, len) == NULL) {
        perror("inet_ntop failed.\n");
        return NULL;
    }
    snprintf(buff + strlen(buff), len, ":%d", ntohl(addr.sin_port));

    return buff;
}

int main(int argc, char* argv[]) {
    signal(SIGCHLD, sig_chld_handler);
    if (argc != 2) {
        printf("usage: %s <port>\n", basename(argv[0]));
        return -1;
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed.\n");
        return -1;
    }

    struct sockaddr_in server_addr, client_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        perror("bind failed.\n");
        return -1;
    }

    if (listen(server_fd, 5) != 0) {
        perror("listen failed.\n");
        return -1;
    }

    char message[1024];
    while (1) {
        printf("%s waitting client...\n", basename(argv[0]));

        socklen_t addr_len = 0;
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (client_fd < 0) {
            perror("accept failed.\n");
            return -1;
        }

        printf("connection from [%s].\n", get_ip_port(client_addr, message, sizeof(message)));

        pid_t pid = fork();
        if (pid < 0) {
            perror("fock failed.\n");
        }
        if (pid == 0) {
            srand(time(NULL));
            int logid = rand();
            while (1) {
                int message_length = 0;
                if (readn(client_fd, (char*)&message_length, sizeof(message_length)) != sizeof(message_length)) {
                    perror("read message_length failed.\n");
                    return -1;
                }
                if (message_length == 0) {
                    break;
                }
                if (readn(client_fd, message, message_length) != message_length) {
                    perror("read message failed.\n");
                    return -1;
                }

                message[message_length] = '\0';
                printf("recv %d bytes message from %d, message [%s]\n", message_length, logid, message);

                if (writen(client_fd, (char*)&message_length, sizeof(message_length)) != sizeof(message_length)) {
                    perror("write message_length failed.\n");
                    return -1;
                }
                if (writen(client_fd, message, message_length) != message_length) {
                    perror("write message failed.\n");
                    return -1;
                }

                printf("send %d bytes message to %d, message [%s]\n", message_length, logid, message);
            }

            printf("disconnect [%s].\n", get_ip_port(client_addr, message, sizeof(message)));
            close(client_fd);
            close(server_fd);
            return 0;
        }
        close(client_fd);
    }
}
