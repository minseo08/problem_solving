#include <iostream>
#include <vector>
using namespace std;
int n, s, e, m;
vector<int> graph[101];
bool visited[101];
bool flag;

void dfs(int cur, int cnt){
    if(cur == e){
        flag = true;
        cout << cnt << "\n";
        return;
    }
    for(int i = 0; i < graph[cur].size(); i++){
        int tmp = graph[cur][i];
        if(!visited[tmp]){
            visited[tmp] = true;
            dfs(tmp, cnt + 1);
        }
    }
    return;
}

int main(){
    cin >> n;
    cin >> s >> e;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited[s] = true;
    dfs(s, 0);
    if(!flag)
        cout << "-1\n";
    return 0;
}