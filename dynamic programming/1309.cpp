#include <iostream>
using namespace std;
int dp[100001];

int main() {
    int n;
    dp[1] = 3;
    dp[2] = 7;
    cin >> n;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
    }
    cout << dp[n];
    return 0;
}