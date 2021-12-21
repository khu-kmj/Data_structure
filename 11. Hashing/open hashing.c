#include <stdio.h>
#include <stdlib.h>
#define MAX 7
#define HASHING(X) X%MAX
typedef struct Node {
	int data;
	struct Node *link;
};
Node *head[MAX];
void init() {
	for (int i = 0; i < MAX; i++)
		head[i] = NULL;
}
void Insert(int item) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->link = NULL;
	newnode->data = item;
	int index = HASHING(item);
	if (head[index] == NULL)
		head[index] = newnode;
	else {
		Node *temp = head[index];
		Node *cur = head[index]->link;
		if (temp->data < item) {
			while (temp->link != NULL && cur->data<item) {
				temp = temp->link;
				cur = cur->link;
			}
			temp->link = newnode;
			newnode->link = cur;
		}
		else {
			newnode->link = head[index];
			head[index] = newnode;
		}
	}
}
void Display() {
	for (int i = 0; i < MAX; i++) {
		printf("[%d] : ", i);
		while (head[i] != NULL) {
			printf("%d->", head[i]->data);
			head[i] = head[i]->link;
		}
		printf("NULL\n");
	}
}
void main(void) {
	init();
	Insert(5);
	Insert(8);
	Insert(1);
	Insert(15);
	Insert(2);
	Insert(16);
	Insert(19);
	Display();
}