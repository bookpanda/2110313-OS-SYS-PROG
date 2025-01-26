#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 100

int main()
{
    char buffer[100];
    if(fgets(buffer, sizeof(buffer), stdin) == NULL || buffer[0] == '\n') {
        printf("Please enter UNIX comamnd\n");
        exit(1);
    }

    // remove trailing newline if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    // tokenize input
    char *command;
    char *av[MAX_ARGS];
    int ac = 0;
    char *saveptr;
    char *p = strtok_r(buffer, " ", &saveptr);

    // first token is the command
    command = p;
    p = strtok_r(NULL, " ", &saveptr); // pass NULL to continue tokenizing the same string

    while (p != NULL && ac < MAX_ARGS - 1) {
        av[ac++] = p;
        p = strtok_r(NULL, " ", &saveptr);
    }
    av[ac] = NULL; // null-terminate the argument list

    printf("Parsed command:\n");
    for (int i = 0; i < ac; ++i) {
        printf("  av[%d] = '%s'\n", i, av[i]);
    }
    
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Error : cannot fork\n");
        exit(1);
    }
    else if (pid == 0) {
        if(ac == 0) {
            execlp(command,command,NULL);
        } else {
            execvp(command,av);
        }
    }
    else {
        wait(NULL);
        return(0);
    }
}