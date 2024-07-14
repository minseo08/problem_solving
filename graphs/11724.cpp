#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> graph[1001];
bool visited[1001];

void dfs(int tmp){
    visited[tmp] = true;
    for(int i = 0; i < graph[tmp].size(); i++){
        if(!visited[graph[tmp][i]]){
            visited[graph[tmp][i]] = true;
            dfs(graph[tmp][i]);
        }
    }
}

int main(){
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}