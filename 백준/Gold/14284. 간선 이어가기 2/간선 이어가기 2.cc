#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int n, m, s, t;
vector<pair<int, int>> graph[5001];
int dp[5001];

void dijk(int cur){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, cur});
    dp[cur] = 0;
    while(!pq.empty()){
        int tx = pq.top().second;
        int td = pq.top().first;
        pq.pop();
        for(int i = 0; i < graph[tx].size(); i++){
            int nx = graph[tx][i].first;
            int nd = graph[tx][i].second;
            if(td + nd < dp[nx]){
                dp[nx] = td + nd;
                pq.push({td + nd, nx});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> s >> t;
    for(int i = 0; i <= n; i++){
        dp[i] = INF;
    }
    dijk(s);
    cout << dp[t];
    return 0;
}