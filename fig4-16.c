#include "apue.h"
#include <fcntl.h>

int main(void) {
    if (open("tempfile", O_RDWR) < 0)
        err_sys("open error");
    if (unlink("tempfile") < 0)
        err_sys("unlink error");
    sleep(15);
    printf("done\n");
    exit(0);
}