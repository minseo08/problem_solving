#include <iostream>
#include <algorithm>
using namespace std;
int dp[31];

int main() {
    int n;
    int res = 0;
    cin >> n;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    if(n % 2 != 0){
        cout << res;
        return 0;
    }
    for(int i = 4; i <= n; i += 2){
        dp[i] = dp[i - 2] * 3;
        for(int j = i - 4; j >= 0; j -= 2)
            dp[i] = dp[i] + (dp[j] * 2);
    }
    cout << dp[n];
    return 0;
}