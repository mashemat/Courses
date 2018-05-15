#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int status;

    pid_t child = fork();
    if (child <= 0)
        exit(4);  // 260
    waitpid(child, &status, 0);
    if (WIFEXITED(status))
        printf("first child exited with %u\n", WEXITSTATUS(status));
}
