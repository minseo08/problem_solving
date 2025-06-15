#include <iostream>
using namespace std;
int dp[10001][4];

// 1 -> 1 (1 0 0)
// 2 -> 2 (1 1 0)
// 3 -> 3 (1 1 1)
// 4 -> 4 (1 2 1)
// 5 -> 5 (1 2 2)
// 6 -> 7 (1 3 3)
// 7 -> 8 (1 3 4)
// 8 -> 10 (1 4 5)

int main(){
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 0;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(int i = 4; i <= 10000; i++){
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int num;
        cin >> num;
        cout << dp[num][1] + dp[num][2] + dp[num][3] << "\n";
    }
    return 0;
}