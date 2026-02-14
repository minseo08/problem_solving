#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        int arr[2][100001];
        int dp[2][100001];
        for(int j = 0; j < 2; j++){
            for(int k = 1; k <= n; k++){
                cin >> arr[j][k];
            }
        }
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        for(int k = 2; k <= n; k++){
            dp[0][k] = max(dp[1][k - 2], dp[1][k - 1]) + arr[0][k];
            dp[1][k] = max(dp[0][k - 2], dp[0][k - 1]) + arr[1][k];
        }
        int res = max(dp[0][n], dp[1][n]);
        cout << res << "\n";
    }
    return 0;
}