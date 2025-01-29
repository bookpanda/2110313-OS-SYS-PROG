#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 100

int main(int argc, char *argv[])
{
    if(argc == 1) {
        printf("Please enter UNIX comamnd\n");
        exit(1);
    }

    // printf("Number of arguments: %d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("Argument %d: %s\n", i, argv[i]);
    // }

    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Error : cannot fork\n");
        exit(1);
    }
    else if (pid == 0) {
        if(argc == 2) {
            execlp(argv[1],argv[1],NULL);
        } else {
            char *av[MAX_ARGS];
            for(int i = 2; i < argc; i++) {
                av[i-1] = argv[i];
            }
            execvp(argv[1],av);
        }
    }
    else {
        wait(NULL);
        return(0);
    }
}