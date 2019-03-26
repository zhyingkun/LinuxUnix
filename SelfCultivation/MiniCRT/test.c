#include "minicrt.h"

void exit_now(){
	printf("Exit Now!\n");
}
int main(int argc, char* argv[]){
	atexit(exit_now);
	char** v = malloc(argc*sizeof(char*));
	int i = 0;
	for(i=0; i<argc; i++){
		v[i] = malloc(strlen(argv[i])+1);
		strcpy(v[i], argv[i]);
	}
	FILE* fp = fopen("test.txt", "w");
	for(i=0; i<argc; i++){
		int len = strlen(v[i]);
		fwrite(fp, &len, 1, sizeof(int));
		fwrite(fp, v[i], 1, len);
	}
	fclose(fp);
	fp = fopen("test.txt", "r");
	for(i=0; i<argc; i++){
		int len;
		fread(fp, &len, 1, sizeof(int));
		char* buf = malloc(len+1);
		fread(fp, buf, 1, len);
		buf[len] = '\0';
		printf("%d %s\n", len, buf);
		free(buf);
		free(v[i]);
	}
	fclose(fp);
}
