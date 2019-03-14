#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

// The Implemention of LinkList
typedef struct ListNode {
	int data;
	bool mark;
	struct ListNode* next;
} ListNode;

typedef struct LinkList {
	ListNode* header;
	ListNode* tailer;
	int count;
} LinkList;

LinkList* CreateLinkList(){
	LinkList* tmpList = (LinkList*)malloc(sizeof(LinkList));
	if (tmpList == NULL) {
		fprintf(stderr, "CreateLinkList: Call malloc error\n");
		return NULL;
	}
	tmpList->header = NULL;
	tmpList->tailer = NULL;
	tmpList->count = 0;
	return tmpList;
}
void DestroyLinkList(LinkList* list){
	ListNode* tmpNode = list->header;
	int allCount = list->count;
	for (int i = 0; i < allCount; i++) {
		ListNode* prevNode = tmpNode;
		tmpNode = tmpNode->next;
		free(prevNode);
		list->count--;
	}
	assert(list->count == 0);
	free(list);
}
bool IsLinkListEmpty(LinkList* list){
	return list->count == 0;
}
int LinkListLength(LinkList* list){
	return list->count;
}
void InsertNode(LinkList* list, int data){
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		fprintf(stderr, "InsertNode: Call malloc error\n");
		return;
	}
	newNode->data = data;
	newNode->mark = false;
	newNode->next = NULL;
	if (list->header == NULL){
		list->header = newNode;
	}
	if (list->tailer != NULL){
		list->tailer->next = newNode;
	}
	list->tailer = newNode;
	list->count++;
}
void DeleteNodeByIndex(LinkList* list, int index){
	if (index < 0 || index > list->count) {
		fprintf(stderr, "DeleteNodeByIndex: Index %d Not Exist\n", index);
		return;
	}
	ListNode* tmpNode = list->header;
	ListNode* prevNode = NULL;
	for (int i = 1; i < index; i++) {
		prevNode = tmpNode;
		tmpNode = tmpNode->next;
	}
	if (prevNode == NULL) {
		list->header = tmpNode->next;
	}else{
		prevNode->next = tmpNode->next;
	}
	free(tmpNode);
	list->count--;
}
void DeleteNodesByData(LinkList* list, int data){
	ListNode* tmpNode = list->header;
	ListNode* prevNode = NULL;
	int allCount = list->count;
	for (int i = 0; i < allCount; i++) {
		if (tmpNode->data == data) {
			if (prevNode == NULL) {
				list->header = tmpNode->next;
			}else{
				prevNode->next = tmpNode->next;
			}
			free(tmpNode);
			list->count--;
		}
		prevNode = tmpNode;
		tmpNode = tmpNode->next;
	}
}
int GetDataByIndex(LinkList* list, int index){
	if (index < 0 || index > list->count) {
		fprintf(stderr, "DeleteNodeByIndex: Index %d Not Exist\n", index);
		return -1;
	}
	ListNode* tmpNode = list->header;
	for (int i = 1; i < index; i++) {
		tmpNode = tmpNode->next;
	}
	return tmpNode->data;
}
int GetIndexByData(LinkList* list, int data){
	ListNode* tmpNode = list->header;
	for (int i = 0; i < list->count; i++) {
		if (tmpNode->data == data) {
			return i+1;
		}
		tmpNode = tmpNode->next;
	}
	return -1;
}
void DisplayLinkList(LinkList* list){
	ListNode* tmpNode = list->header;
	for (int i = 0; i < list->count; i++) {
		printf("LinkList: %d ==> %d\n", i+1, tmpNode->data);
		tmpNode = tmpNode->next;
	}
}
void MakeLinkListLooping(LinkList* list){
	list->tailer->next = list->header;
}
bool IsLinkListLooping(LinkList* list){
	ListNode* pointerOne = list->header;
	ListNode* pointerTwo = list->header->next;
	for (; (pointerOne != NULL)&&(pointerTwo != NULL);) {
		if (pointerOne == pointerTwo) {
			return true;
		}
		pointerOne = pointerOne->next;
		pointerTwo = pointerTwo->next;
		if (pointerTwo == NULL) {
			return false;
		}
		pointerTwo = pointerTwo->next;
	}
	return false;
}
void ClearMarks(LinkList* list){
	ListNode* tmpNode = list->header;
	for (int i = 0; i < list->count; i++) {
		tmpNode->mark = false;
		tmpNode = tmpNode->next;
	}
}
bool IsLinkListLoopingOne(LinkList* list){
	ClearMarks(list);
	ListNode* tmpNode = list->header;
	for (; tmpNode != NULL; ) {
		if (tmpNode->mark) {
			return true;
		}
		tmpNode->mark = true;
		tmpNode = tmpNode->next;
	}
	return false;
}
bool IsLinkListLoopingTwo(LinkList* list){
	ClearMarks(list);
	int* markNode[64];
	for (int i = 0; i < 64; i++) {
		markNode[i] = NULL;
	}
	ListNode* tmpNode = list->header;
	for (; tmpNode != NULL; ) {
		int i = 0;
		for (i = 0; markNode[i] != NULL; i++) {
			if (markNode[i] == &tmpNode->data) {
				return true;
			}
		}
		markNode[i] = &tmpNode->data;
		tmpNode = tmpNode->next;
	}
	return false;
}
bool IsLinkListLoopingThree(LinkList* list){
	ListNode* tmpNode = list->header;
	for (int i = 0; tmpNode != NULL; i++) {
		ListNode* loopNode = list->header;
		for (int j = 0; j < i; j++) {
			if (tmpNode == loopNode) {
				return true;
			}
			loopNode = loopNode->next;
		}
		tmpNode = tmpNode->next;
	}
	return false;
}
// End of LinkList

int main(int argc, char* argv[])
{
	(void)argc; (void)argv;
	printf("zykTest\n");
	LinkList* myList = CreateLinkList();
	InsertNode(myList, 12);
	InsertNode(myList, 42);
	InsertNode(myList, 57);
	InsertNode(myList, 15);
	InsertNode(myList, 88);
	InsertNode(myList, 79);
	DisplayLinkList(myList);
	DeleteNodeByIndex(myList, 3);
	DisplayLinkList(myList);
	DeleteNodesByData(myList, 88);
	DisplayLinkList(myList);
	printf("Is LinkList Looping Now: %d\n", (int)IsLinkListLooping(myList));
	printf("Is LinkList Looping One: %d\n", (int)IsLinkListLoopingOne(myList));
	printf("Is LinkList Looping Two: %d\n", (int)IsLinkListLoopingTwo(myList));
	printf("Is LinkList Looping Thr: %d\n", (int)IsLinkListLoopingThree(myList));
	MakeLinkListLooping(myList);
	printf("Is LinkList Looping Now: %d\n", (int)IsLinkListLooping(myList));
	printf("Is LinkList Looping One: %d\n", (int)IsLinkListLoopingOne(myList));
	printf("Is LinkList Looping Two: %d\n", (int)IsLinkListLoopingTwo(myList));
	printf("Is LinkList Looping Thr: %d\n", (int)IsLinkListLoopingThree(myList));
	DestroyLinkList(myList);
	return 0;
}
