#include <stdio.h>
#include <gnu/libc-version.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){

	int fd = open("./test2.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fd<0){
		perror("open():");
		exit(1);
	}
	dup2(fd,1);
	puts("hello");
	return 0;
}
