#include "apue.h"
#include <sys/wait.h>

#define MAXCHAR 4096

void sig_int(int signo) {
    printf("interrupt\n%%");
}

int main (void) {
    char buf[MAXCHAR];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%%");
    while (fgets(buf, MAXCHAR, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;

        if ((pid = fork()) < 0 )
            err_sys("fork error");
        else if (pid == 0) {
            execlp(buf, buf, 0 );
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");

        printf("%%"); 
    }

    exit(0);
}
