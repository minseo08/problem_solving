#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 1100
#define INF 987654321
using namespace std;
pair<int, int> arr[21];
int dp[21][1110];

int main(){
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < 1110; j++)
            dp[i][j] = INF;
    }
    int c, n;
    cin >> c >> n;
    arr[0].first = 0;
    arr[0].second = 0;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    int res = INF;
    for(int i = 1; i <= n; i++){
        dp[i][0] = 0;
        for(int j = 1; j <= MAX; j++){
            if(j >= arr[i].second){
                dp[i][j] = dp[i][j - arr[i].second] + arr[i].first;
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
        for(int j = c; j <= MAX; j++){
            res = min(res, dp[i][j]);
        }
    }
    cout << res;
    return 0;
}

