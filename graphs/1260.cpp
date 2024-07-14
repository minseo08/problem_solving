#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> graph[1001];
vector<int> result_dfs;
vector<int> result_bfs;
bool visited[1001];

void bfs(int tmp){
    queue<int> q;
    q.push(tmp);
    visited[tmp] = true;
    while(!q.empty()){
        int num = q.front();
        result_bfs.push_back(num);
        q.pop();
        for(int i = 0; i < graph[num].size(); i++){
            if(!visited[graph[num][i]]){
                q.push(graph[num][i]);
                visited[graph[num][i]] = true;
            }
        }
    }
}

void dfs(int tmp){
    if(!visited[tmp]){
        visited[tmp] = true;
        result_dfs.push_back(tmp);
        for(int i = 0; i < graph[tmp].size(); i++){
            dfs(graph[tmp][i]);
        }
    }
}

int main(){
    int n, m, v;
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    for(int i = 0; i < result_dfs.size(); i++){
        cout << result_dfs[i] << " ";
    }
    cout << "\n";
    memset(visited, false, sizeof(visited));
    bfs(v);
    for(int i = 0; i < result_bfs.size(); i++){
        cout << result_bfs[i] << " ";
    } 
    return 0;
}