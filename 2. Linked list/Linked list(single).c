#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node *L;
}Node;
void del(Node **head, int item) {
	if ((*head)->data == item) {
		*head = (*head)->L;
	}
	else {
		Node *before=*head;
		Node *cur = (*head)->L;
		while (cur->data != item) {
			before = before->L;
			cur = cur->L;
		}
		before->L = cur->L;
		free(cur);
	}
}
void insert(Node **head, int item) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->L = NULL;
	newnode->data = item;
	if (*head == NULL) 
		*head = newnode;
	else {
		//내림  차순 
		/*newnode->L = *head;
		*head = newnode;*/
		//오름  차순
		Node *temp = *head;
		while (temp->L != NULL)
			temp = temp->L;
		temp->L = newnode;
	}
}
void Display(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->L;
	}
}
Node *reverse(Node *head) {
	Node *r, *q, *p;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->L;
		q->L = r;
	}
	return q;
}
int main(void) {
	Node *head = NULL;
	for (int i = 0; i < 6; i++)
		insert(&head, i);
	Display(head);
	printf("\n");
	////////////역 함수////////////////////////
	head = reverse(head);
	Display(head);
	//////////삭제 함수///////////////////////
	del(&head,0);
	printf("\n");
	Display(head);
	del(&head, 3);
	printf("\n");
	Display(head);
	del(&head, 5);
	printf("\n");
	Display(head);
	del(&head, 2);
	printf("\n");
	Display(head);
	del(&head, 1);
	printf("\n");
	Display(head);
	/////////////////////////////////////////
	return 0;
}