#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> graph[100001];
queue<int> q;
bool visited[100001];
int res[100001];
int cnt = 0;
void dfs(int cur){
    visited[cur] = true;
    q.push(cur);
    while(!q.empty() && visited[q.front()] == true){
        int tmp = q.front();
        q.pop();
        cnt++;
        res[tmp] = cnt;
        while(!graph[tmp].empty()){
            int adj = graph[tmp].top();
            graph[tmp].pop();
            if(!visited[adj]){
                visited[adj] = true;
                q.push(adj);
            }
        }
    }
}

int main(){
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push(b);
        graph[b].push(a);
    }
    dfs(r);
    for(int i = 1; i <= n; i++){
        cout << res[i] << "\n";
    }
    return 0;
}