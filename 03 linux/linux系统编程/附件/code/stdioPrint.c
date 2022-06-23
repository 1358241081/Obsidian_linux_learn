#include <stdio.h>
#include <gnu/libc-version.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    printf("%d %d %d\n",O_RDONLY,O_WRONLY,O_RDWR);
    return 0;
}
