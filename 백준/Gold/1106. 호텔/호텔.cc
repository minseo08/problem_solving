#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 2001
using namespace std;
pair<int, int> arr[21];
int dp[21][MAX];

int main(){
    int c, n;
    cin >> c >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second; // 비용,고객
    }
    for(int i = 0; i < 21; i++){
        for(int j = 1; j < MAX; j++)
            dp[i][j] = INF;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < MAX; j++){
            if(j >= arr[i].second){
                dp[i][j] = min(dp[i][j - arr[i].second] + arr[i].first, dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int res = INF;
    for(int i = 1; i <= n; i++){
        for(int j = c; j < MAX; j++)
            res = min(res, dp[i][j]);
        //     cout << dp[i][j] << " ";
        // cout << "\n";
    }
    cout << res;
    
    return 0;
}
