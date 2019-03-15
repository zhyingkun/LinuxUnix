#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXTOKENS 100
#define MAXTOKENLEN 64

typedef enum type_tag { IDENTIFIER, QUALIFIER, TYPE } type_tag;

typedef struct token {
	char type;
	char string[MAXTOKENLEN];
} token;

typedef struct CdeclState {
    token currentToken;
    token stack[MAXTOKENS];
    int top;
	char* cdeclStr;
} CdeclState;

CdeclState* CreateCdeclState(char* cdeclStr) {
    CdeclState* tmpState = (CdeclState*)malloc(sizeof(CdeclState));
    tmpState->top = -1;
	tmpState->cdeclStr = cdeclStr;
	if (cdeclStr != NULL) {
		int len = strlen(cdeclStr);
		for (int i = len - 1; i >= 0; i--) {
			ungetc(cdeclStr[i], stdin);
		}
	}
    return tmpState;
}
void DestroyCdeclState(CdeclState* state) {
    free(state);
}
void PushCurrentTokenToStack(CdeclState* state) {
    state->top++;
    state->stack[state->top] = state->currentToken;
}
token PopFromStack(CdeclState* state) {
    token tmpToken = state->stack[state->top];
    state->top--;
    return tmpToken;
}
void ClassifyString(CdeclState* state) {
    char* s = state->currentToken.string;
	if(!strcmp(s, "const")){
		strcpy(s, "read-only");
		state->currentToken.type = QUALIFIER;
		return;
	}
	if(!strcmp(s, "volatile")) {
		state->currentToken.type = QUALIFIER;
		return;
	}
	if(!strcmp(s, "void")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "char")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "signed")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "unsigned")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "short")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "int")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "long")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "float")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "double")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "struct")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "union")) {
		state->currentToken.type = TYPE;
		return;
	}
	if(!strcmp(s, "enum")) {
		state->currentToken.type = TYPE;
		return;
	}
	state->currentToken.type = IDENTIFIER;
	return;
}
void GetToken(CdeclState* state) {
    char* p = state->currentToken.string;
	while((*p = getchar()) == ' ');
	if(isalnum(*p)){
		while(isalnum(*++p = getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		ClassifyString(state);
		return;
	}
	if(*p == '*'){
		strcpy(state->currentToken.string, "pointer to");
		state->currentToken.type = '*';
		return;
	}
	state->currentToken.string[1] = '\0';
	state->currentToken.type = *p;
	return;
}
void ReadToFirstIdentifier(CdeclState* state){
	GetToken(state);
	while(state->currentToken.type != IDENTIFIER){
        PushCurrentTokenToStack(state);
		GetToken(state);
	}
	printf("%s is ", state->currentToken.string);
	GetToken(state);
}
void DealWithArrays(CdeclState* state){
	while(state->currentToken.type == '['){
		printf("array ");
		GetToken(state);
		if(isdigit(state->currentToken.string[0])){
			printf("0..%d ", atoi(state->currentToken.string)-1);
			GetToken(state);
		}
		GetToken(state);
		printf("of ");
	}
}
void DealWithFunctionArgs(CdeclState* state){
	while(state->currentToken.type != ')'){
		GetToken(state);
	}
	GetToken(state);
	printf("function returning ");
}

void DealWithPointers(CdeclState* state){
	while(state->stack[state->top].type == '*'){
        token tmpToken = PopFromStack(state);
		printf("%s ", tmpToken.string);
	}
}

void DealWithDeclarator(CdeclState* state){
	switch(state->currentToken.type){
		case '[': DealWithArrays(state); break;
		case '(': DealWithFunctionArgs(state);break;
	}
	DealWithPointers(state);
	while(state->top >= 0){
		if(state->stack[state->top].type == '('){
			PopFromStack(state);
			GetToken(state);
			DealWithDeclarator(state);
		}else{
            token tmpToken = PopFromStack(state);
			printf("%s ", tmpToken.string);
		}
	}
}

int main(int argc, char* argv[]){
    (void)argc; (void)argv;
	printf("Start:\n");
	char* cdeclStr = "char* (*c[10])(int **p);";
	// if cdeclStr == NULL, then read from stdin
    CdeclState* state = CreateCdeclState(cdeclStr);
	ReadToFirstIdentifier(state);
	DealWithDeclarator(state);
	printf("\n");
    DestroyCdeclState(state);
	return 0;
}

// Test Example(Input from stdin): char* (*c[10])(int **p);
