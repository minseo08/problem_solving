#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> graph[100001];
bool visited[100001];
int res[100001];
queue<int> q;
int n, m, r, count = 0;

void bfs(int cur){
    visited[cur] = true;
    q.push(cur);
    while(!q.empty()){
        int tmp = q.front();
        count++;
        res[tmp] = count;
        q.pop();
        while(!graph[tmp].empty()){
            if(!visited[graph[tmp].top()]){
                visited[graph[tmp].top()] = true;
                q.push(graph[tmp].top());
            }
            graph[tmp].pop();
        }
    }
}

int main(){
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int v_1, v_2;
        cin >> v_1 >> v_2;
        graph[v_1].push(v_2);
        graph[v_2].push(v_1);
    }
    bfs(r);
    for(int i = 1; i <= n; i++){
        cout << res[i] << "\n";
    }
    return 0;
}