#include <iostream>
using namespace std;
int dp[100001]; // 현재까지의 거스름돈 최소 개수

int main(){
    int n;
    cin >> n;
    dp[1] = -1;
    dp[2] = 1;
    dp[3] = -1;
    dp[4] = 2;
    dp[5] = 1;
    for(int i = 6; i <= n; i++){
        dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
        if(dp[i - 2] < 0 || dp[i - 5] < 0){
            if(dp[i - 2] < 0 && dp[i - 5] < 0)
                dp[i] = -1;
            else
                dp[i] = max(dp[i - 2] + 1, dp[i - 5] + 1);
        }
    }
    if(dp[n] < 0)
        cout << -1;
    else
        cout << dp[n];
    return 0;
}