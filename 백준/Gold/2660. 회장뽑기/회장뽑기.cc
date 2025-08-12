#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
vector<int> graph[51];
int dp[51][51];
int n;

void fw(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < graph[i].size(); j++){
            dp[i][graph[i][j]] = 1;
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
            }
        }
    }
}

int main(){
    cin >> n;
    vector<pair<int, int>> ans;
    priority_queue<int, vector<int>, greater<int>> pq; 
    while(1){
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1){
            break;
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j)
                dp[i][j] = INF;
        }
    }
    fw();

    for(int i = 1; i <= n; i++){
        int score = 0;
        for(int j = 1; j <= n; j++){
            score = max(score, dp[i][j]);
        }
        ans.push_back({score, i});
    }
    sort(ans.begin(), ans.end());
    int pivot = 0;
    int cnt = 0;
    for(int i = 0; i < ans.size(); i++){
        if(i == 0)
            pivot = ans[i].first;
        if(ans[i].first == pivot)
            cnt++;
    }
    cout << pivot << " " << cnt << "\n";
    for(int i = 0; i < cnt; i++)
        cout << ans[i].second << " ";
    return 0;
}

