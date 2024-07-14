#include <iostream>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    int dp[12];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i = 4; i < 12; i++)
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]);
        
    for(int i = 0; i < n; i++){
        cin >> a;
        cout << dp[a] << "\n";
    }
    return 0;
}