#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int arr[501];
int sum[501];
int dp[501][501];
int t, b;
int main(){
    cin >> t;
    for(int a = 0; a < t; a++){
        cin >> b;
        for(int i = 1; i <= b; i++){
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        for(int i = 1; i <= b; i++){            
            for(int j = 1; j <= b - i; j++){
                dp[j][i + j] = INF;
                for(int k = j; k < i + j; k++){
                    dp[j][i + j] = min(dp[j][i + j], sum[i + j] - sum[j - 1] + dp[j][k] + dp[k + 1][i + j]);
                }   
            }
        }
        cout << dp[1][b] << "\n";
    }
    return 0;
}