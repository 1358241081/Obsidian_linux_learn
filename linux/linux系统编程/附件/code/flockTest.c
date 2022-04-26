#include <sys/file.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc,char*argv[]){
    int fd,lock;
    const char * lname;
    lock = argv[2][0] =='s'?LOCK_SH:LOCK_EX;
    if(argv[2][1] == 'n'){
        lock|=LOCK_NB;
    }

    fd =open(argv[1],O_RDONLY);
    if(fd == -1)
        return -1;
    lname = lock&LOCK_SH ? "LOCK_SH":"LOCK_EX";

    printf("PID %ld: %s\n",(long)getpid(),lname);

    if(flock(fd,lock)==-1){
        if(errno == EWOULDBLOCK)
            printf("PID %ld: 已经加锁\n",(long)getpid());
        else
            return -1;
    }

    sleep(60);

    flock(fd,LOCK_UN);
    return 0;
}