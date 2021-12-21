#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int item;
	struct Node *link;
}Node;
Node *rear, *front;
void init() {
	front = rear = NULL;
}
int is_full() {
	return 0;
}
int is_empty() {
	return front == NULL;
}
int delqueue() {
	Node *temp = front;
	if (is_empty()) {
		printf("queu empty");
		exit(1);
	}
	else {
		int item = temp->item;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		free(temp);
		return item;
	}
}
void enqueue(int item) {
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->item = item;
	newnode->link = NULL;
	if (is_empty()) {
		front = newnode;
		rear = newnode;
	}
	else {
		rear->link = newnode;
		rear = newnode;
	}
}
int main(void) {
	for (int i = 0; i < 5; i++)
		enqueue(i + 2);
	printf("%d\n",delqueue());
	printf("%d\n", delqueue());
	return 0;
}