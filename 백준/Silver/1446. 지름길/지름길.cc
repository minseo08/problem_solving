#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int dp[10001];
int n, d;

void init(){
    for(int i = 0; i <= d; i++)
        dp[i] = i;
}

int main(){
    cin >> n >> d;
    vector<pair<pair<int, int>, int>> point;
    init();
    for(int i = 0; i < n; i++){
        int s, e, p;
        cin >> s >> e >> p;
        if(e - s < p || e > d)
            continue;
        point.push_back({{s, e}, p});
    }
    sort(point.begin(), point.end());
    for(int i = 0; i < point.size(); i++){
        dp[point[i].first.second] = min(dp[point[i].first.first] + point[i].second, dp[point[i].first.second]);
        for(int j = i + 1; j < point.size(); j++){
            if(point[j].first.first > point[i].first.second)
                dp[point[j].first.first] = min(dp[point[i].first.second] + point[j].first.first - point[i].first.second, dp[point[j].first.first]);
        }
        dp[d] = min(dp[d], dp[point[i].first.second] + d - point[i].first.second);
    }
    cout << dp[d];
    return 0;
}