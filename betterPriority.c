//used for fork() nice()
#include<unistd.h>
//pritnf need stdio 
#include<stdio.h>
//to use PRIO_PROCESS constant 
#include<sys/resource.h>
// to use exit() 
#include<stdlib.h>
//use wait function 
#include<sys/wait.h>
int main(){
    int who; 
    int which=PRIO_PROCESS;
    int pid; 
    int prio, niceV;

    pid = getpid(); 
    printf("orignal ps with pid %d\n", pid);

    who = fork();
    if(who ==0){
        pid = getpid(); 
        printf("child 1 ps with pid %d\n", pid);
        prio= getpriority(which,pid);
        printf("child 1 ps with priority %d\n", prio);
        niceV =nice(19);
        prio= getpriority(which,pid);
        printf("child 1 ps changed nice to %d, now with priority %d\n", niceV,prio);
        puts("child 1 is terminating now");
        puts("");
        exit(11);
    }
    else{
        sleep(5);
        // will ensure the completion of first forked child 
        int status; 
        puts("parents start waiting for child 1 now");
        int ret = wait(&status);
        puts("parents end child 1 waiting ");
        printf("child 1 %d ps terminate with status %d \n", ret,status);
        
        puts("");
        printf("parents ps with pid %d\n", pid);
        prio= getpriority(which,pid);
        printf("parents ps with priority %d\n", prio);
        niceV =nice(11);
        prio= getpriority(which,pid);
        printf("parents ps changed nice to %d, now with priority %d\n", niceV,prio);

        puts("");
        who = fork(); 
        if(who == 0){
            sleep(5);
            pid = getpid(); 
            printf("child 2 ps with pid %d\n", pid);
            prio= getpriority(which,pid);
            printf("child 2 ps with priority %d\n", prio);
            niceV =nice(19);
            prio= getpriority(which,pid);
            printf("child 2 ps changed nice to %d, now with priority %d\n", niceV,prio);
            puts("child 2 is terminating now");
            puts("");
            exit(2);
        }
        else{
            puts("parents start waiting now");
            ret = wait(&status);
            printf("child 2 %d ps terminate with status %d\n", ret,status);
            puts("parents end waiting ");
        }
    }

}
