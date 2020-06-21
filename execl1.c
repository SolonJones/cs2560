// this program test the fork excel wait and exit fucntion 
// unistd constains many important constant and read() write() _exit() lseek() fork() execl()
//
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]) { 

        int pid;
        //this var is used to hold the return status of fork to deternmin which part is executing 

	printf("Before: process id %d\n",getpid());
    // first getpid() will return the parents pid 
    //fork return twice 
    //first identity of processing ps 
    // -1 will indicate fork() fail 0 indicate its child >0 means its parents (actually parents pid)
	if ((pid = fork())==0){
		printf("I am the child %d\n",getpid());  
		sleep(5);
        // sleep allow the threading to be scheduled for parents 
		printf("Listing content of current directory...\n");  
        // finish sleeping 
		execl("/bin/ls","ls","-l", (char *)0);
        // now child will trump all existing code and reload /bin/ls to pass on command ls with -l 
        // after the complete this command child return 0 for int main()
	}
	else{
		printf("I am the parent %d\n", getpid());  

		int status;
        // parens create a status int, by passing it to wait, it will listen to child ps's termination return 
		int term_pid = wait(&status);
        // this will pause the parents ps until the child has return termination status  
        // the wait() will return the cid 
        printf("the status value from child should be 0 the actuall is: %d\n", status);
		printf("Child %d has listed the content of current directory\n",
			 term_pid);  
		exit(1);
	}
}

