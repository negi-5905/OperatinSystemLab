// given an array calculate even no. sum in parent process and odd no. sum in child process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int even_sum = 0, odd_sum = 0;
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 != 0) {
                odd_sum += arr[i];
            }
        }
        wait(NULL); 
        printf("Child Process: Odd Sum = %d\n", odd_sum);
    } else {
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) {
                even_sum += arr[i];
            }
        }
        printf("Parent Process: Even Sum = %d\n", even_sum);
        exit(0);
    }

    return 0;
}
