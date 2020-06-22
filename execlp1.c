#include <unistd.h>
// unistd is for open read write fork execl _exit gitpid 
#include <stdio.h>
//sys/wait.h is for wait and waitpid() 
#include <sys/wait.h>
#include <stdlib.h>
//stdlib is for exit()

int main(int argc, char* argv[]) {  
	int who;
	printf("parents' process id is %d\n",getpid());

	if ((who = fork())==0){
		printf("I am child with fork return of %d and my id is %d\n", who, getpid());  
        // fork will return 0 to child ps and cpid to parent ps 
		sleep(5);
		printf("done with sleeping, now I will execlp() all rest of command \n");  
		execlp("ls","ls","-l", (char *)0);
        // this only diff from offeriong default path 
        printf("fuck up");
        exit(100);
	}
	else{
		printf("I am parents thread with who value of %d id of %d \n", who, getpid());  
        int status;
	    	
		int cid = wait(&status);
		printf("wait() had return chld id %d have terminated \n", cid);
        printf("expect 0 for status: actual is %d", status);
        exit(1);
	}
}
