#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void inet_usage() {
    struct in_addr inaddr;
    char addrstr[] = "192.168.1.1";

    // inet_aton, inet_ntoa
    if (inet_aton(addrstr, &inaddr) == 0) {
        printf("inet_aton failed. %s is not a vaild address\n", addrstr);
    }
    printf("inaddr address is %s\n", inet_ntoa(inaddr));

    // inet_pton, inet_ntop
    // 增加一个family参数，支持IPv6
    if (inet_pton(AF_INET, addrstr, &inaddr) == 0) {
        printf("inet_pton failed. %s is not a valid address\n", addrstr);
    }
    inet_ntop(AF_INET, &inaddr, addrstr, sizeof(addrstr));
    printf("inaddr address is %s\n", addrstr);
}

int main(int argc, char* argv[]) {
    inet_usage();

    return 0;
}
