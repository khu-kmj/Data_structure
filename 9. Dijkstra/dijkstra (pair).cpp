#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999
#define MAX 20002
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int V, E, start;
    cin >> V >> E >> start;
    vector<pair<int, int> > arr[MAX];

    for (int i = 0; i < E; i++) {
        int from, to, val;
        cin >> from >> to >> val;
        arr[from].push_back({ to,val });
    }
    int dist[MAX];
    fill(dist, dist + V + 1, INF);     
    priority_queue<pair<int, int>> qu;
    qu.push({ 0,start });
    dist[start] = 0;    
    while (!qu.empty()) {
        int cost = -qu.top().first;
        int here = qu.top().second;    
        qu.pop();
        for (int i = 0; i < arr[here].size(); i++) {
            int next = arr[here][i].first;
            int nextcost = arr[here][i].second;
            if (dist[next] > cost + nextcost) {
                dist[next] = cost + nextcost;
                qu.push({-dist[next], next });
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)cout << "INF" << "\n";
        else cout << dist[i] <<"\n";
    }
   
    return 0;
}
