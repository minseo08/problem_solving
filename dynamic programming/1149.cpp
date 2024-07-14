#include <iostream>
using namespace std;
int dp[1001][4];
int main() {
    int n;
    cin >> n;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        
        dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + a;
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + b;
        dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + c;
    }
    cout << min(min(dp[n][1], dp[n][2]), dp[n][3]);
    return 0;
}