#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[1001];
int dp[1001];
int arr[1001];
int n, m;
void dijk(int tmp){
    for(int i = 1; i <= n; i++){
        dp[i] = INF;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, tmp});
    dp[tmp] = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int city = pq.top().second;
        pq.pop();
        if(dist > dp[city]){
            continue;
        }
        for(int k = 0; k < graph[city].size(); k++){
            if(dist + graph[city][k].second < dp[graph[city][k].first]){
                arr[graph[city][k].first] = city;
                dp[graph[city][k].first] = dist + graph[city][k].second;
                pq.push({dist + graph[city][k].second, graph[city][k].first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    int s, e;
    cin >> s >> e;
    dijk(s);
    cout << dp[e] << "\n";
    vector<int> vec;
    vec.push_back(e);
    int temp = arr[e];
    while(temp != s){
        vec.push_back(temp);
        temp = arr[temp];
    }
    vec.push_back(s);
    cout << vec.size() << "\n";
    for(int i = vec.size() - 1; i >= 0; i--){
        cout << vec[i] << " ";
    }
    
    return 0;
}