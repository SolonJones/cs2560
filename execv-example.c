#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

	char *const av[]={"ls", "-l", (char *)0};

	printf(" executing ls\n");
	
	execv("/bin/ls",av);

	perror("excel failed to run ls");

	exit (1);
}
