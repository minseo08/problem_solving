#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[1001];
    for(int i = 1; i <= n; i++){
        cin >> dp[i];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }
    cout << dp[n];
    return 0;
}