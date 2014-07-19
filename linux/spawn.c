#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#define BUFFSIZE 4096

int main(void){
    char buf[BUFFSIZE];
    int status;
    pid_t pid;
    printf("%% ");
    while( fgets(buf,BUFFSIZE,stdin) != NULL){
        if(buf[strlen(buf)-1] == '\n' )
            buf[strlen(buf)-1]=0;

        if((pid = fork()) <0){
            printf("fork error\n");
            exit(1);
        }else if(pid == 0 ){//child
            execlp(buf,buf,(char*)0);
            printf("could not execut %s\n",buf);
            exit(127);
        }
        
        if( (pid =waitpid(pid,&status, 0)) <0)
            printf("wait error\n");

        printf("%% ");
    }

    exit(0);
}
