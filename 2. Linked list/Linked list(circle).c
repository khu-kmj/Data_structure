#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* L;
}Node;

void insert(Node** head, int item) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->L = NULL;
	newnode->data = item;
	if (*head == NULL) {
		*head = newnode;
		newnode->L = *head;
	}
	else {
		Node* temp = *head;
		while (temp->L != *head)
			temp = temp->L;
		temp->L = newnode;
		newnode->L = *head;
	}
}
void Del(Node** head, int item) {

	Node* cur = (*head)->L;
	Node* bef = *head;
	while (cur->data != item) {
		cur = cur->L;
		bef = bef->L;
	}
	bef->L = cur->L;
	if ((*head)->data == item) {
		*head = bef->L;
	}


}
void Display(Node* head) {
	Node* temp = head;
	while (temp->L != head) {
		printf("%d->", temp->data);
		temp = temp->L;
	}
	printf("%d", temp->data);
}

int main(void) {
	Node* head = NULL;
	for (int i = 0; i < 5; i++)
		insert(&head, i);
	Display(head);
	printf("\n");
	Del(&head, 0);
	Display(head);
	printf("\n");
	Del(&head, 3);
	Display(head);
	insert(&head, 0);
	printf("\n");
	Display(head);

}