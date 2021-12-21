#include <stdio.h>
#include <stdlib.h>
#define MAX 8
int rear = -1;
int front = -1;
int arr[MAX];
int is_empty() {
	return front == rear;
}
int is_full() {
	return ((rear+1)%MAX)  == front;
}

void enqueue(int item) {
	if (is_full()) {
		printf("원형 큐 가득 찼습니다!\n");
		exit(1);
	}
	else {
		rear = (rear + 1) % MAX;
		arr[rear] = item;
	}

}
int delqueue() {
	if (is_empty()) {
		printf("비어있는데 뭘 뺍니까?\n");
		exit(1);
	}
	else {
		front = (front + 1) % MAX;
		int item= arr[front];
		arr[front] = NULL;
		return item;
	}
}
void Display(int item) {
	printf("입력/삭제 아이템 : %d\n", item);
	printf("Front : %d, Rear : %d\n", front, rear);
	for (int i = 0; i < MAX; i++) {
		printf("Queue : [%d]%d ",i, arr[i]);
	}
	printf("\n");
}
int main(void) {

	for (int i = 0; i < MAX; i++) {
		enqueue(i + 2);
		Display(i + 2);
	}
	Display(delqueue());
	Display(delqueue());
	Display(delqueue());
	Display(delqueue());
	return 0;
}