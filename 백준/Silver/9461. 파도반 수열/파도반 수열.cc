#include <iostream>
using namespace std;
long long dp[101];

int main(){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        if(n >= 4){
            for(int j = 4; j <= n; j++){
                dp[j] = dp[j - 3] + dp[j - 2];
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}