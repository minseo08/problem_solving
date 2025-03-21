#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][10001];
vector<pair<int, int>> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t;
    cin >> n >> t;
    vec.push_back(make_pair(0, 0));
    for(int i = 1; i <= n; i++){
        int time, score;
        cin >> time >> score;
        vec.push_back(make_pair(time, score));
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= t; j++){
            if(j >= vec[i].first)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec[i].first] + vec[i].second);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][t];
    return 0;
}