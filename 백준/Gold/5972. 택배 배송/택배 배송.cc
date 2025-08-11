#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[50001];
int dp[50001];

void dijk(int tmp){
    dp[tmp] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, tmp});
    while(!pq.empty()){
        int cur_x = pq.top().second;
        int cur_d = pq.top().first;
        pq.pop();
        for(int i = 0; i < graph[cur_x].size(); i++){
            int nd = graph[cur_x][i].first + cur_d;
            int nx = graph[cur_x][i].second;
            if(dp[nx] > nd){
                dp[nx] = nd;
                pq.push({dp[nx], nx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    for(int i = 1; i <= n; i++)
        dp[i] = INF;
    dijk(1);
    cout << dp[n];
    return 0;
}