#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void launch_shell () {
    setuid(0);
    system("/bin/sh");
}

int check_authentication(char *password,char* msg) {
    char password_buffer[16];
    strcpy(password_buffer, password);
    printf(msg);
    if (strcmp(password_buffer, "dumbledore") == 0)
        return 1;
    if (strcmp(password_buffer, "gandalf") == 0)
        return 1;
    return 0;
 }

int main(int argc, char *argv[]) {
    if (argc < 3) { 
        printf("Usage: %s <password> <message>\n", argv[0]); 
        exit(0); 
    } else if (check_authentication(argv[1],argv[2])) 
    { 
        launch_shell();
    }
    else printf("\nAccess Denied.\n");
}
