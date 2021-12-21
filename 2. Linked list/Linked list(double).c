#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* L;
	struct Node* R;
}Node;

void Del(Node** head, int item) {
	if ((*head)->data == item) {
		*head = (*head)->L;
		(*head)->R = NULL;
	}
	else {
		Node* bef = *head;
		Node* cur = (*head)->L;
		while (cur->data != item) {
			bef = bef->L;
			cur = cur->L;
		}
		if (cur->L == NULL) {
			bef->L = NULL;
			free(cur);
		}
		else {
			bef->L = cur->L;
			cur->L->R = bef;
			free(cur);
		}
	}
}
void insert(Node** head, int item) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->L = NULL;
	newnode->R = NULL;
	newnode->data = item;
	if (*head == NULL)
		*head = newnode;
	else {
		Node* temp = *head;
		while (temp->L != NULL)
			temp = temp->L;
		temp->L = newnode;
		newnode->R = temp;
	}
}
void Display(Node* head) {
	Node* temp = head;
	while (temp->L != NULL) {
		printf("%d->", temp->data);
		temp = temp->L;
	}
	while (temp->R != NULL) {
		printf("%d->", temp->data);
		temp = temp->R;
	}
	printf("%d", temp->data);
}

int main(void) {
	Node* head = NULL;
	for (int i = 0; i < 5; i++)
		insert(&head, i);
	Display(head);
	printf("\n");
	Del(&head, 4);
	Display(head);
	printf("\n");
	Del(&head, 2);
	Display(head);
	printf("\n");
	Del(&head, 0);
	Display(head);
}