#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[101];
queue<int> q;
bool visited[101];
int cnt = 0;

void bfs(int num){
    visited[num] = true;
    q.push(num);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i = 0; i < graph[tmp].size(); i++){
            if(!visited[graph[tmp][i]]){
                visited[graph[tmp][i]] = true;
                q.push(graph[tmp][i]);
                cnt++;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    cout << cnt;
    return 0;
}