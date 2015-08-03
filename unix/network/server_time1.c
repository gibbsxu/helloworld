// 单进程时间服务器

#include <stdio.h>          // printf, perror
#include <time.h>           // time
#include <string.h>         // bzero
#include <unistd.h>         // fork, read, write, close
#include <sys/socket.h>     // socket, bind, listen, accept
#include <netinet/in.h>     // htonl, htons, ntohs
#include <arpa/inet.h>      // inet_ntop

int main(int argc, char* argv[]) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed.\n");
        return -1;
    }

    struct sockaddr_in server_addr, client_addr;

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(6666);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        perror("bind failed.\n");
        return -1;
    }

    if (listen(server_fd, 5) != 0) {
        perror("listen failed.\n");
        return -1;
    }

    char buff[1024];
    while (1) {
        printf("waitting client...\n");

        socklen_t addr_len = 0;
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (client_fd < 0) {
            perror("accept failed.\n");
            return -1;
        }
        printf("connection from %s, port %d\n",
            inet_ntop(AF_INET, &client_addr.sin_addr, buff, sizeof(buff)),
            ntohs(client_addr.sin_port));
        time_t ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\n", ctime(&ticks));
        write(client_fd, buff, sizeof(buff));

        close(client_fd);
    }
}
