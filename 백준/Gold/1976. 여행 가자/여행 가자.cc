#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[201];
bool visited[201];
void dfs(int tmp){
    visited[tmp] = true;
    for(int i = 0; i < graph[tmp].size(); i++){
        if(!visited[graph[tmp][i]]){
            dfs(graph[tmp][i]);
        }
    }
}

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int a;
            cin >> a;
            if(a == 1){
                graph[i].push_back(j);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int b;
        cin >> b;
        if(!visited[b]){
            cnt++;
            dfs(b);
        }
    }
    if(cnt == 1){
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}