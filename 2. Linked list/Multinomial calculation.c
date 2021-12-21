#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int coef;  //계수
	int expon; //지수
	struct Node *link;
}Node;
void insert(Node **head, int coef, int expon) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->link = NULL;
	newnode->coef = coef;
	newnode->expon = expon;
	if (*head == NULL)
		*head = newnode;
	else {
		Node *temp = *head;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = newnode;
	}
}
void compare(Node **thr, Node **one, Node **two) {
	Node *temp_one = *one;
	Node *temp_two = *two;
	while (temp_one != NULL || temp_two != NULL) {
		if (temp_one->expon > temp_two->expon) {
			insert(thr, temp_one->coef, temp_one->expon);
			temp_one = temp_one->link;
		}
		else if (temp_one->expon == temp_two->expon) {
			insert(thr, temp_one->coef+temp_two->coef, temp_one->expon);
			temp_one = temp_one->link;
			temp_two = temp_two->link;
		}
		else {
			insert(thr, temp_two->coef, temp_two->expon);
			temp_two=temp_two->link;
		}
	}
	if (temp_one == NULL && temp_two!=NULL) {
		while (temp_two != NULL) {
			insert(thr, temp_two->coef, temp_two->expon);
			temp_two = temp_two->link;
		}
	}
	else if (temp_two == NULL && temp_one != NULL) {
		while (temp_one != NULL) {
			insert(thr, temp_one->coef, temp_one->expon);
			temp_one = temp_one->link;
		}
	}
}
void Display(Node *head) {
	Node *temp = head;
	while (temp != NULL) {
		printf("%dx^%d  ", temp->coef, temp->expon);
		temp = temp->link;
	}
	printf("\n");
}
int main(void) {
	int arr[6] = { 5,3,-3,1,1,0 };//5x^2-3x+1
	int brr[6] = { 4,3,4,1,1,0 };//4x^3+4x+1 
	//4x^3 + 5x^2 + x+2
	Node *head_one = NULL;
	Node *head_two = NULL;
	Node *head_thr = NULL;
	for (int i = 0; i < sizeof(arr) / 4; i = i + 2) {
		insert(&head_one, arr[i],arr[i+1]);
		insert(&head_two, brr[i], brr[i + 1]);
	}
	Display(head_one);
	Display(head_two);
	compare(&head_thr, &head_one, &head_two);
	Display(head_thr);
	return 0;
}