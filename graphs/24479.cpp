#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, r, cnt = 1;
priority_queue<int, vector<int>, greater<int>> graph[100001];
bool visited[100001];
int res[100001];
void dfs(int cur){
    visited[cur] = true;
    res[cur] = cnt;
    cnt++;
    while(!graph[cur].empty()){
        int tmp = graph[cur].top();
        graph[cur].pop();
        if(!visited[tmp]){
            dfs(tmp);
        }
    }
}

int main(){
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