#include <iostream>
#include <vector>
using namespace std;
bool visited[10001];
vector<pair<int, int>> graph[10001];
int res = 0;
int res_point = 0;

void dfs(int cur, int len){
    visited[cur] = true;
    if(len > res){
        res = len;
        res_point = cur;
    }
    for(int i = 0; i < graph[cur].size(); i++){
        if(!visited[graph[cur][i].first])
            dfs(graph[cur][i].first, len + graph[cur][i].second);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});        
    }
    dfs(1, 0);
    res = 0;
    for(int i = 0; i <= n; i++)
        visited[i] = false;
    dfs(res_point, 0);
    cout << res;
    return 0;
}