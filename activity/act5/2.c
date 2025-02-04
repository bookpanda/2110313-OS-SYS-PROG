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

int main()
{
    pthread_t t[10];

    for(int i=0;i<10;i++) {
        char *str = malloc(100);
        if (str == NULL) {
            perror("Failed to allocate memory");
            return 1;
        }
        sprintf(str, "This is thread %d", i+1);

        pthread_create(&t[i], NULL, print_text, str);
    }

    for(int i=0;i<10;i++) {
        pthread_join(t[i], NULL);
    }

    return 0;
}
