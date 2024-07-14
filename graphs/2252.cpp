#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> graph[32001];
bool visited[32001];
stack<int> s;

void dfs(int tmp){
    visited[tmp] = true;
    for(int i = 0; i < graph[tmp].size(); i++){
        if(!visited[graph[tmp][i]]){
            dfs(graph[tmp][i]);
        }
    }
    s.push(tmp);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i);
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}