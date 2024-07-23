#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
long long INF = 987654321;
vector<pair<int, int>> graph[4001];
long long dp[4001];
long long dp_2[2][4001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq_2;
void dijk_1(int tmp){
    for(int i = 1; i <= n; i++){
        dp[i] = INF;
    }
    pq.push({0, tmp});
    dp[tmp] = 0;
    while(!pq.empty()){
        long long dist = pq.top().first;
        int t = pq.top().second;
        pq.pop();
        if(dist > dp[t]){
            continue;
        }
        for(int i = 0; i < graph[t].size(); i++){
            if(dp[graph[t][i].first] > dist + (long long)graph[t][i].second){
                dp[graph[t][i].first] = dist + (long long)graph[t][i].second;
                pq.push({dist + (long long)graph[t][i].second, graph[t][i].first});
            }
        }
    }
}

void dijk_2(int tmp){
    for(int i = 0; i <= n; ++i){
        dp_2[0][i] = INF;
        dp_2[1][i] = INF;
    }
    pq_2.push({0, {0, tmp}});
    dp_2[0][tmp] = 0;
    while(!pq_2.empty()){
        long long dist = pq_2.top().first;
        int k = 1 - pq_2.top().second.first;
        int t = pq_2.top().second.second;
        pq_2.pop();
        if(dist > dp_2[1 - k][t]){
            continue;
        }
        for(int i = 0; i < graph[t].size(); i++){
            long long new_dist;
            if(k == 1){
                new_dist = dist + (long long)graph[t][i].second;
            }
            else{
                new_dist = dist + (long long)graph[t][i].second * 4;
            }
            if(dp_2[k][graph[t][i].first] > new_dist){
                dp_2[k][graph[t][i].first] = new_dist;
                pq_2.push({dp_2[k][graph[t][i].first], {k, graph[t][i].first}});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back(make_pair(b, d));
        graph[b].push_back(make_pair(a, d));
    }
    dijk_1(1);
    dijk_2(1);
    // for(int i = 1; i <= n; i++){
    //     cout << dp[i]*2 << " ";
    // }
    // for(int i = 1; i <= n; i++){
    //     cout << min(dp_2[0][i], dp_2[1][i]) << " ";
    // }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(dp[i]*2 < min(dp_2[0][i], dp_2[1][i])){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}