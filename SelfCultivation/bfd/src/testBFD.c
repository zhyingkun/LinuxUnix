#include <stdio.h>
#include <bfd.h>
int main(int argc, char* argv[]){
	const char** t = bfd_target_list();
	for(int i=0; t[i]!=NULL; i++){
		printf("%s\n", t[i]);
	}
	return 0;
}
