#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void process_http_msg(char *msg)
{
    char buf[100];
    strcpy(buf, msg);
    printf("Processing %s\n", buf);
    /* Add server code here */
}

int main(int argc, char *argv[])
{
   if (argc < 2) {
        printf("Usage: %s <http_msg>\n", argv[0]);
        exit(0);
   }
   process_http_msg(argv[1]);
}
