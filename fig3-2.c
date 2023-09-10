#include "apue.h"
#include <fcntl.h>

char buf[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void) {
    int fd;

    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("creat error");

    if (write(fd, buf, 10) != 10)
        err_sys("write error");

    if (lseek(fd, 16384, SEEK_CUR) == -1)
        err_sys("lseek error");

    if (write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    
    exit(0);
}