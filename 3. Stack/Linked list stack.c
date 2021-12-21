#include <stdio.h>
#include <stdlib.h>
typedef struct StackNode { 
	int item;	
	struct StackNode *link; 
}StackNodeTypedef; 


int is_empty(StackNodeTypedef *s) {
	return (s== NULL);
}
void push(StackNodeTypedef **top, int item) {
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	temp->link = NULL;
	temp->item = item;
	if (*top == NULL) {
		*top = temp;
	}
	else {
		temp->link = *top;
		*top = temp;
	}
}
int pop(StackNodeTypedef *s) {
	if (is_empty(s)) {
		printf("스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode *temp = s;
		int item = temp->item;
		s = s->link;
		free(temp);
		return item;
	}
}
void main(void) {
	StackNode *top = NULL;
	push(&top, 1);
	push(&top, 2);
	push(&top, 3);
	push(&top, 4);
	push(&top, 5);
	printf("%d", pop(top));
}