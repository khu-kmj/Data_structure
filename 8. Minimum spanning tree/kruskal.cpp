#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

/* 
★ kruskal ★
(1) 간선들을 오름차순 정렬 (이 때 두 노드의 정보를 가지고 있어야 함)
(2) 정렬된 것의 첫 번째부터 연결
    > 사이클 형성하는지 검사해야 함
	> 사이클 형성한다면 다음 것 검사
(3) 부분적으로 연결된 그래프를 합치기 (union)
 
 시간 복잡도 : O(eloge) <-log2e
 */

// 재귀를 통해 부모 노드를 찾고 바환
int getParent(int parent[], int node){
	if(parent[node] == node) { 
		return node; 
	} 
	return getParent(parent, parent[node]); 
} 
// 두 노드의 부모노드를 합침 
int unionParent(int parent[], int x, int y){ 
	x = getParent(parent, x);
	y = getParent(parent, y); 
	if(x < y){ 
		parent[y] = x; 
		return x; 
	}
	else { 
		parent[x] = y; 
		return y; 
	} 
}
// 같은 부모노드를 갖는지 확인 
int findParent(int parent[], int x, int y){ 
	x = getParent(parent, x); 
	y = getParent(parent, y); 
	if(x == y){ // 같은 부모 노드 
		return 1; 
	}else{ // 다른 부모 노드 
		return 0; 
	}
} 
// 간선들의 정보 
class Edge{ 
public: 
	int node[2]; // x-y 이렇게 연결하기 위해서 크기가 2인 node
	int distance; 
	Edge(int x, int y, int distance){ 
		this->node[0] = x; 
		this->node[1] = y; 
		this->distance = distance; 
	} 
	// sort 함수 시 Edge의 distance를 기준으로 sort하라는 것
	bool operator <(Edge &edge){ 
		return distance < edge.distance; 
	} 
}; 
int main() { 
	int n; // 노드의 개수 
	int m; // 간선의 개수 
	cin >> n >> m;
	vector<Edge> v; 
	int* parent = new int[n];
	for (int i = 0; i < m; i++) {
		int ve, e, w;
		cin >> ve >> e >> w;
		v.push_back(Edge(ve, e, w));
	}
	// 거리를 오름차순으로 정렬 
	sort(v.begin(), v.end()); 
	for(int i=0; i<n; i++) 
		parent[i] = i; 
	int sum = 0; 
	for(int i=0; i<v.size(); i++){ 
		// 다른 부모를 가지는 경우 = 사이클이 생기지 않는 경우
		if(!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)){ 
			sum += v[i].distance;  
			unionParent(parent, v[i].node[0]-1, v[i].node[1]-1); // 합치기
		}
	} 
	cout << sum; 
	delete[] parent;
	return 0; 
}

