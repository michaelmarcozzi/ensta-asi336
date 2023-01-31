#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argv-fuzz-inl.h"

char *command ;

int concat_with_ls (char folder_name[])
{ 
     command = (char *) malloc (16 * sizeof(char));
     strcpy (command, "ls ");
     if (strlen(folder_name) + 1 + strlen(command) + 1 > 16)
     { 
          printf("Filename too long !\n"); 
          free(command); 
          return 0; 
     }
     strcat(command, folder_name); 
     return 1 ;
}


int main(int argc, char *argv[]) 
{
     AFL_INIT_ARGV();
     if (argc < 2) { 
        printf("Usage: %s <folder> \n", argv[0]); 
        printf("Prints content of <folder> \n"); 
        exit(0); 
     } 
     char *error_message;
     if (!concat_with_ls(argv[1])) 
     {
          printf("Error:: Enter your log message (< 24 characters)\n");
          error_message = (char *) malloc (24 * sizeof (char)); 
          scanf("%23s", error_message); 
          /* Save error in logs */
     } 
     system(command) ;
     strcpy(command, "echo in folder"); 
     system(command);    
     return 0 ;
}
