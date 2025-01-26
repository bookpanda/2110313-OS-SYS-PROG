#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int compute_period = 5;
int sleep_period = 5;

void on_alarm(int signal) {
    printf("Sleep\n");
    sleep(sleep_period);
    printf("Wake up\n");
    alarm(compute_period);
}

int main() {
    printf("Enter compute period (seconds): ");
    scanf("%d", &compute_period);
    printf("Enter sleep period (seconds): ");
    scanf("%d", &sleep_period);

    if (compute_period <= 0 || sleep_period <= 0) {
        printf("Error: Both periods must be positive integers.\n");
        exit(1);
    }

    signal(SIGALRM, on_alarm);
    alarm(compute_period);

    for (int i = 0;; i++) {
        if (i == 0) printf("Computing\n");
    }

    return 0;
}
