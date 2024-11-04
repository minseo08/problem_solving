#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
vector<pair<int, int>> vec[1001];
int dp[1001];
int n, m, s, e;

void dijk(int cur){
    for(int i = 1; i <= n; i++)
        dp[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, cur});
    dp[cur] = 0;
    while(!pq.empty()){
        int x = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost > dp[x])
            continue;
        for(int i = 0; i < vec[x].size(); i++){
            int new_x = vec[x][i].first;
            int new_cost = cost + vec[x][i].second;
            if(dp[new_x] > new_cost){
                dp[new_x] = new_cost;
                pq.push({new_cost, new_x});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }
    cin >> s >> e;
    dijk(s);
    cout << dp[e];
    return 0;
}