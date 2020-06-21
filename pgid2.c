#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/wait.h>

int main(int argc, char *argv[]){  

	int pid = getpid();

	printf("Parent: PID = %d, PPID = %d, PGID = %d\n",pid,getppid(),getpgid(pid));

	if ((pid = fork())==0){

		printf("Child: PID = %d, PPID = %d, PGID = %d\n",  
			getpid(),getppid(),getpgid(getpid()));
		exit(1);
	}
	sleep(5);
}

