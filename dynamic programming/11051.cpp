#include <iostream>
using namespace std;
int dp[1001][1001];

int main(){
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)
                dp[i][0] = 1;
            else if(j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[n][k];
    return 0;
}
