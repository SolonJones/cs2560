#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char* argv[]) { 
	 int pid;
	printf("I am the parent %d. My priority is %d\n",  
			getpid(),getpriority(PRIO_PROCESS,getpid()));

	if ((pid = fork())==0){
		printf("I am the child %d. My priority is %d\n",  
			getpid(),getpriority(PRIO_PROCESS,getpid()));
		printf("Child: nice(19) returns %d\n",nice(19));  
		printf("I am the child %d. My priority is now %d\n",
		getpid(),getpriority(PRIO_PROCESS,getpid()));  
		exit(20);
	}
	else{
		sleep(5);
		printf("Changing parent’s priority...\n");  
		printf("Parent: nice(10) returns %d\n",nice(10));  

		int status;
		int term_pid = wait(&status);

		int new_pid = fork();  

		if (new_pid == 0){
			printf("I am the new child %d. My priority is %d\n", 
			 getpid(),getpriority(PRIO_PROCESS,getpid()));
			printf("New child: nice(5) returns %d\n",nice(5));  
			printf("I am the new child %d. My priority is now %d\n",
				getpid(),getpriority(PRIO_PROCESS,getpid()));  
			exit(21);
		}
		else term_pid = wait(&status);
	}
}

