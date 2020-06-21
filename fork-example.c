#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid;

	printf("Just one process so far \n");
	printf("calling fork()...\n");

	pid=fork();

	if(pid==0)
		printf("I am the child\n");
	else if (pid>0)
		printf("I am the parent, child has pid:%d\n", pid);
	else
		printf("Fork returned error code, no child\n");

}
