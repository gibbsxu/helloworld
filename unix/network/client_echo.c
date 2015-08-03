// echo客户端
// 接收数据格式：message_length | message
// 发送数据格式：message_length | message

#include <stdio.h>          // printf, perror
#include <string.h>         // strncmp
#include <stdlib.h>         // atoi
#include <unistd.h>         // close
#include <sys/socket.h>     // socket, connect
#include <netinet/in.h>     // htons
#include <arpa/inet.h>      // inet_pton

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

int main(int argc, char* argv[]) {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("socket failed.\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        perror("connect failed.\n");
        return -1;
    }

    char send_buff[1024];
    char recv_buff[1024];

    while (fgets(send_buff, sizeof(send_buff), stdin) > 0) {
        if (strncmp(send_buff, "exit", 4) == 0) {
            break;
        }
        int message_length = strlen(send_buff) - 1;
        if (message_length == 0) {
            break;
        }
        send_buff[message_length] = '\0';
        if (writen(client_fd, (char*)&message_length, sizeof(message_length)) != sizeof(message_length)) {
            perror("write message_length failed.\n");
            return -1;
        }
        if (writen(client_fd, send_buff, message_length) != message_length) {
            perror("write message failed.\n");
            return -1;
        }

        printf("send %d bytes message [%s].\n", message_length, send_buff);

        if (readn(client_fd, (char*)&message_length, sizeof(message_length)) != sizeof(message_length)) {
            perror("read message_length failed.\n");
            return -1;
        }
        if (readn(client_fd, recv_buff, message_length) != message_length) {
            perror("read message failed.\n");
            return -1;
        }

        printf("recv %d bytes message [%s].\n", message_length, recv_buff);
    }

    printf("exit...\n");
    int message_length = 0;
    if (writen(client_fd, (char*)&message_length, sizeof(message_length)) != sizeof(message_length)) {
        perror("writen failed.\n");
        return -1;
    }

    close(client_fd);

    return 0;
}
