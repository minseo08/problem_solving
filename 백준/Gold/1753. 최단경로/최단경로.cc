#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[20001];
int dp[20001];

void dijk(int tmp){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, tmp});
    dp[tmp] = 0;
    while(!pq.empty()){
        int tx = pq.top().second;
        int td = pq.top().first;
        pq.pop();
        for(int i = 0; i < graph[tx].size(); i++){
            int nx = graph[tx][i].first;
            int nd = graph[tx][i].second;
            if(dp[nx] > td + nd){
                dp[nx] = td + nd;
                pq.push({td + nd, nx});
            }
        }
    }
}

int main(){
    int v, e, s;
    cin >> v >> e;
    cin >> s;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    for(int i = 1; i <= v; i++){
        dp[i] = INF;
    }
    dijk(s);
    for(int i = 1; i <= v; i++){
        if(dp[i] < INF)
            cout << dp[i] << "\n";
        else
            cout << "INF" << "\n";
    }
    return 0;
}