#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[100001];
int citizen[100001];
int dp[100001][2];
vector<int> graph[100001];

void dfs(int tmp){
    visited[tmp] = true;
    dp[tmp][0] = 0;
    dp[tmp][1] = citizen[tmp];
    
    for(int i = 0; i < graph[tmp].size(); i++){
        if(!visited[graph[tmp][i]]){
            dfs(graph[tmp][i]);
            dp[tmp][0] += max(dp[graph[tmp][i]][0], dp[graph[tmp][i]][1]);
            dp[tmp][1] += dp[graph[tmp][i]][0];
        }
    }

}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> citizen[i];
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}