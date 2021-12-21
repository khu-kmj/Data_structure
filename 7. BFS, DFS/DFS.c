#include <stdio.h>
#define VERTEX 7

void Insert_edge(int mat[VERTEX][VERTEX], int start, int end) {
	mat[start][end] = 1;
	mat[end][start] = 1;
}

void dfs_mat(int mat[VERTEX][VERTEX], int v, int dfs_visited[VERTEX]) {
	dfs_visited[v] = 1;
	printf("%d -> ", v);
	for (int i = 0; i < VERTEX; i++) {
		if (mat[v][i] == 1 && dfs_visited[i] == 0)
			dfs_mat(mat, i, dfs_visited);
	}
}
void main() {
	int mat[VERTEX][VERTEX] = { 0 };
	int dfs_visited[VERTEX] = { 0 };

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

	dfs_mat(mat, 0, dfs_visited);
}
