#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    int n = 3;
    int i;
    pid_t childpid;
    for (i = 0; i < n; ++i) {
        childpid = fork();
        if (childpid > 0)
            break;
    }
    if(i == 0)
        printf("I am the parent process. My PID is %d\n", (long) getpid());
    else if(i == 1)
        printf("I am the child process. My PID is %d and my parent's PID is %d\n", (long) getpid(), (long) getppid());
    else if(i == 2)
        printf("I am the grandchild process. My PID is %d and my parent's PID is %d\n", (long) getpid(), (long) getppid());
    wait(0);
}