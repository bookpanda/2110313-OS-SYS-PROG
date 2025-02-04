#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void* print_text(void* data)
{
    char *str;
    str = (char*)data;
    printf("%s\n",str);
    free(str);
    sleep(1);

    return NULL;
}

void create_threads(char* processName) {
    pthread_t t[2];

    for(int i=0;i<2;i++) {
        char *str = malloc(100);
        if (str == NULL) {
            perror("Failed to allocate memory");
            return;
        }
        if(i == 0)  sprintf(str, "First thread from %s process: %ld", processName, (long) getpid());
        else sprintf(str, "Second thread from %s process: %ld", processName, (long) getpid());

        pthread_create(&t[i], NULL, print_text, str);
    }

    for(int i=0;i<2;i++) {
        pthread_join(t[i], NULL);
    }
}

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Error : cannot fork\n");
        exit(1);
    } else if (pid == 0) {
        create_threads("child");
    } else {
        create_threads("parent");
    }    
     wait(0);

    return 0;
}
