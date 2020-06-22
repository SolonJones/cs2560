#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int docommand(char *command) {
    execl("/bin/bash", "bash", "-c", command, (char*)0);
    perror("excel");
    exit(1);
}

int main(){
    int who;
    who = fork();
    if(who ==-1){
        perror("fork");
    }
    else if(who == 0){
        docommand("ls -lt");
    }
    else{
        printf("parents %d real do nothing but wait for child %d to complete", getpid(), who);
        wait((int *)NULL);
    }
}
