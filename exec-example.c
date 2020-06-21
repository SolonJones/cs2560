#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

	printf(" executing ls\n");
	
	//execl("/bin/ls", "ls", "-l", (char *)0);

	//execlp("ls","ls",  "-l", (char *)0);

	perror("excel failed to run ls");

	exit (1);
}
