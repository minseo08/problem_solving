#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[501];
long long dp[501];
int n, m;
void bell(int tmp){
    for(int i = 1; i <= n; i++){
        dp[i] = INF;
    }
    dp[tmp] = 0;
    for(int k = 1; k <= n - 1; k++){
        for(int i = 1; i <= n; i++){
            if(dp[i] == INF){
                continue;
            }
            for(int j = 0; j < graph[i].size(); j++){
                if(graph[i][j].second + dp[i] < dp[graph[i][j].first]){
                    dp[graph[i][j].first] = graph[i][j].second + dp[i];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dp[i] == INF){
            continue;
        }
        for(int j = 0; j < graph[i].size(); j++){
            if(graph[i][j].second + dp[i] < dp[graph[i][j].first]){
                cout << -1 << "\n";
                return;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(i == tmp){
            continue;
        }
        if(dp[i] == INF){
            cout << -1 << "\n";
        }
        else{
            cout << dp[i] << "\n";
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].push_back({e, d});
    }
    bell(1);
    return 0;
}