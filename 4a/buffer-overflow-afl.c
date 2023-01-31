#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argv-fuzz-inl.h"

int check_authentication(char *password) {
    int auth_flag = 0;
    char password_buffer[10];
    strcpy(password_buffer, password);
    if (strcmp(password_buffer, "dumbledore") == 0)
        auth_flag = 1;
    if (strcmp(password_buffer, "gandalf") == 0)
        auth_flag = 1;
    return auth_flag;
 }

int main(int argc, char *argv[]) {
    AFL_INIT_ARGV();
    if (argc < 2) { 
        printf("Usage: %s <password>\n", argv[0]); 
        exit(0); 
    } else if (check_authentication(argv[1])) 
    { 
        /* Code doing sensitive actions here */
        printf("\nSensitive actions done.\n");
    }
    else printf("\nAccess Denied.\n");
}

