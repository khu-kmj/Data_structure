#include <stdio.h>
#define VERTEX 7
#define Q_SIZE 10

int queue[Q_SIZE];
int front = 0, rear = 0;

int is_empty() {
	return rear == front;
}
void enqueue(int item) {
	if ((rear + 1) % Q_SIZE == front) {
		printf("가득\n");
		return;
	}
	rear = (rear + 1) % Q_SIZE;
	queue[rear] = item;
}
int dequeue() {
	if (is_empty()) {
		printf("빈공간\n");
		return 0;
	}
	front = (front + 1) % Q_SIZE;
	return queue[front];
}
void Insert_edge(int mat[VERTEX][VERTEX], int start, int end) {
	mat[start][end] = 1;
	mat[end][start] = 1;
}
void bfs_mat(int mat[VERTEX][VERTEX], int v, int bfs_visited[VERTEX]) {
	bfs_visited[v] = 1;
	printf("%d -> ", v);
	enqueue(v);
	while (!is_empty()) {
		v = dequeue();
		for (int i = 0; i < VERTEX; i++) {
			if (bfs_visited[i] == 0 && mat[v][i] == 1) {
				enqueue(i);
				bfs_visited[i] = 1;
				printf("%d -> ", i);
			}
		}
	}
}

void main() {
	int mat[VERTEX][VERTEX] = { 0 };
	int bfs_visited[VERTEX] = { 0 };

	Insert_edge(mat, 0, 1);
	Insert_edge(mat, 0, 2);
	Insert_edge(mat, 1, 3);
	Insert_edge(mat, 1, 4);
	Insert_edge(mat, 2, 3);
	Insert_edge(mat, 2, 5);
	Insert_edge(mat, 3, 4);
	Insert_edge(mat, 3, 5);
	Insert_edge(mat, 4, 6);
	Insert_edge(mat, 5, 6);

	bfs_mat(mat, 0, bfs_visited);
}
