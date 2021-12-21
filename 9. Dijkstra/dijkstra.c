#include <stdio.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define NODES	7		/* 노드의 수 */
#define INF 	9999	/* 무한 값(연결이 없는 경우) */
int distance[NODES];/* 시작노드로부터의 최단경로 거리 */
int found[NODES];		/* 방문한 노드 표시 */
int prob[NODES];
int cost[NODES][NODES] = {
	{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0} };

int choose(int distance[], int n,int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void shortest_path(int start, int n)
{
	int i, u, w;
	for (i = 0; i < n; i++) /* 초기화 */
	{
		distance[i] = cost[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* 시작노드 방문 표시 */
	distance[start] = 0;
	for (i = 0; i < n; i++) {
		u = choose(distance, n, found);
		found[u] = TRUE;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
					prob[w] = u;
				}
	}
}
void moving(int j) {
	printf("%d<-", j);
	while (j != 0) {
		int a = prob[j];
		printf("%d<-", prob[j]);
		j = a;
	}
}
void main(){
	shortest_path(0, NODES);

	for (int i = 0; i < 7; i++)
		printf("[%d] : %d\n", i, distance[i]);
	for (int i = 0; i < 7; i++)
		printf("%d\n", prob[i]); 
	
	moving(2);


}