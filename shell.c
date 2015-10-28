#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/wait.h>

#define SIZE 10

void *shellThread (void *data) {

	pid_t id;
	char *str = (char *)data;
	char *tag;

	str = strtok(str," ");
	tag = strtok(NULL," ");

	id = fork();
	if(id == -1) {
		perror("Error: ");
		pthread_exit(NULL);	
	}
	
	if(id == 0) {
		if(execlp(str,str,tag,NULL) == -1) 
				perror("Error in loading program.\n");
		}
	else 
		if(wait(NULL) == -1) {
			perror("Error.\n");
		}    //using wait for child process to finish
	

	pthread_exit(NULL);

}


int main(int argc, char const *argv[])
{
	pthread_t tidshell;
	//int n;
	char str[SIZE];

	do {

		printf("\ncdac@user_shell: ");
		gets(str);

	if(strcmp(str,"exit") != 0) {
		if(pthread_create(&tidshell,NULL,shellThread,&str) != 0) {
			printf("Error in creating thread.\n");
			return 0;
		}
	}
	
	pthread_join(tidshell,NULL);

	}while(strcmp(str,"exit") != 0);


	return 0;
}