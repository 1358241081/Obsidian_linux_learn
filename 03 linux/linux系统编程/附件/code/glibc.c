#include <stdio.h>
#include <gnu/libc-version.h>


int main(){
    printf("GLIBC :%d\t GLIBC_MINOR :%d\n",__GLIBC__,__GLIBC_MINOR__);
    printf("%s\n",gnu_get_libc_version());
    printf("hello world!\n");
    return 0;
}
