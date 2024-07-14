#include <iostream>
#include <algorithm>
using namespace std;
int arr[2][100001];
int dp[2][100001];

int main() {
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < 2; j++){
            for(int k = 1; k <= n; k++)
                cin >> arr[j][k];
        }
        
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        for(int i = 2; i <= n; i++){
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
        }
        cout << max(dp[0][n], dp[1][n]) << "\n";
    }
    
    return 0;
}