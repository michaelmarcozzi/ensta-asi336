#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char user_input[10];


void check_password_and_proceed (unsigned long password) {
    if (strtoul(user_input,NULL,0) == password)  {
         /* Code doing sensitive actions here */
         printf("\nDoing sensitive actions.\n");
    }
    else {
        printf("\nError: input ");
        printf(user_input);
        printf(" is not a valid password.\n");
    }
}

int main (int argc,char *argv[]) {
    scanf("%[^\n]s",user_input);
    // Password is 3735928559 (0xdeadbeef in hex)
    check_password_and_proceed(0xdeadbeef);  
}
