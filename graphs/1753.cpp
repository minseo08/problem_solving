#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
int v, e, k;
int dp[20001];
vector<pair<int, int>> vec[20001];

void dijk(int tmp){
    for(int i = 1; i <= v; i++){
        dp[i] = INF;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, tmp});
    dp[tmp] = 0;
    while(!pq.empty()){
        int x = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for(int i = 0; i < vec[x].size(); i++){
            int nx = vec[x][i].first;
            int ncost = cost + vec[x][i].second;
            if(dp[nx] > ncost){
                pq.push({ncost, nx});
                dp[nx] = ncost;
            }
        }
    }
}

int main(){
    cin >> v >> e >> k;
    int a, b, c;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
    }
    dijk(k);
    for(int i = 1; i <= v; i++){
        if(dp[i] < INF){
            cout << dp[i] << "\n";
        }
        else{
            cout << "INF" << "\n";
        }
    }
    return 0;
}