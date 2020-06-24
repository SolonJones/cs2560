/*
 * Question 1
 * part1 
    Write a C program  such that the parent process generates ONE child process and this child process generates its own ONE child process (which becomes the grandchild process of the initial parent process. The situation is as shown in the diagram below
                                        Parent process  (249121)
                                                    |
                                                    |
                                        Child process (249122)
                                                    |
                                                    |
                                        (grand)Child process (249123)
    Use sleep function if necessary to coordinate among the 3 processes in the picture such that
part2:

    The grand child process becomes a zombie, and the parent process waits (using the waitpid function) for its child process to terminate and prints its exit status value (of your choice).
    The output from your program should be similar to the following screenshot.
    see picture 
    Script your terminal session with timing log option to show how your program compiles andruns.
    */

/************************************
 * first part 
 * make fork()
 */

//using fork and getpid getppid sleep
#include<unistd.h>
//using printf  perror
#include<stdio.h>
//suing exit 
#include<stdlib.h>
//usinsg wait 
#include<sys/wait.h>


int main(){
    int who, pid, ppid, cpid, status; 
    pid = getpid(); 
    printf("before fork, parents id is %d\n", pid); 
    who = fork(); 
    switch(who){
        case -1: 
            perror("fork");
            break; 
        case 0: 
            ppid = getppid(); 
            pid = getpid(); 
            printf("hi I am child 1, my pid is %d, my parents id is %d\n", pid, ppid); 
            who = fork(); 
            switch(who){
                case -1: 
                    perror("fork");
                    break; 
                case 0: 
                    ppid = getppid(); 
                    pid = getpid(); 
                    printf("hi I am grand child, my pid is %d, my parents id is %d\n", pid, ppid); 
                    puts("Done, join the zombine land ");
                    exit(2);
                    break; 
                default:
                        sleep(1);
                        //exit(1);
            }           // child 1 did not wait for child 2 
            break; 
        default:
            puts("parents wait"); 
            //printf("who: %d", who);
            cpid = waitpid(who,&status,WUNTRACED); 
            sleep(3);
            printf("child 1 %d terminated, termination status is %d\n", cpid, status); 
            // parents only wait for child 1 
    }

}
