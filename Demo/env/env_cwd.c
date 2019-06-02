#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for chdir

int main()
{
	char *penv = NULL;
	char *path;

	penv = getenv("PATH");
	if(penv == NULL){
		printf("get env error\n");
		return 0;
	}
	printf("%s\n",penv);

	path = malloc(strlen(penv)+15);
	strcpy(path,"PATH=");
	strcat(path,penv);
	strcat(path,":./");
	putenv(path);
	penv = getenv("PATH");
	if(penv == NULL){
		printf("get env error\n");
		return 0;
	}
	printf("%s\n",penv);

	char* pwd = getenv("PWD");
	printf("$PWD: %s\n", pwd);
	char buffer[1024];
	getcwd(buffer, 1024);
	printf("getcwd: %s\n", buffer);
	chdir("/home/zyk");
	pwd = getenv("PWD");
	printf("$PWD: %s\n", pwd);
	getcwd(buffer, 1024);
	printf("getcwd: %s\n", buffer);
	return 0;
}

