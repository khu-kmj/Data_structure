#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int arr[MAX];
int top = -1;
int is_full() {
	return top == MAX - 1;
}
int is_empty() {
	return top == -1;
}
void push(int item) {
	if (is_full()) {
		perror("full");
		exit(1);
	}
	arr[++top] = item;
}
int pop() {
	if (is_empty()) {
		perror("empty");
		exit(1);
	}
	return arr[top--];
}
void Print() {
	for (int i = 0; i <= top; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
void main() {
	push(1);
	push(2);
	push(3);
	Print();
	printf("pop : %d\n", pop());
	printf("pop : %d\n", pop());
	printf("pop : %d\n", pop());

}