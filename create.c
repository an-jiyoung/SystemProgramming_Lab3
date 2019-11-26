#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if(pid == -1) {
		printf("can't fork, erro\n");
		exit(0);
	}
	if(pid == 0) {
		int j;
		for(j = 0; j < 10; j++) {
			printf("child: %d\n" , j);
			sleep(1);
		}
		exit(0);
	} else {
		int i;
		for(i = 0; i < 10; i++) {
			printf("parent : %d\n", i);
			sleep(1);
		}
		exit(0);
	}
	return 0;
}
