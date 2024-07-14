#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int dp[MAX];
bool visited[MAX];

void dfs(int tmp, int parent){
    visited[tmp] = true;
    for(int i = 0; i < graph[tmp].size(); i++){
        if(!visited[graph[tmp][i]]){
            dfs(graph[tmp][i], tmp);
        }
    }
    if(parent != 0)
        dp[parent] += dp[tmp];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, r, q;
    cin >> n >> r >> q;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    fill_n(dp, MAX, 1);
    dfs(r, 0);
    for(int i = 0; i < q; i++){
        int a;
        cin >> a;
        cout << dp[a] << "\n";
    }
    return 0;
}