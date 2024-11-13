#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, r, cnt = 0;
//vector<int> graph[100001];
priority_queue<int> graph[100001];
bool visited[100001];
int res[100001];

void dfs(int cur){
    visited[cur] = true;
    cnt++;
    res[cur] = cnt;
    //cout << cur << "\n";
    while(!graph[cur].empty()){
        int tmp = graph[cur].top();
        if(!visited[tmp]){
            dfs(tmp);
        }
        graph[cur].pop();
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
    for(int i = 1; i <= n; i++)
        cout << res[i] << "\n";
    return 0;
}