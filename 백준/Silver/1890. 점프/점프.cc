#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][101];
long long dp[101][101];

int main(){
    int n;
    cin >> n;
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            int p = arr[i][j];
            if(!dp[i][j] || (i == n - 1 && j == n - 1))
                continue;
            if(i + p < n){
                dp[i + p][j] += dp[i][j];
            }
            if(j + p < n){
                dp[i][j + p] += dp[i][j];
            }
        }
    }

    cout << dp[n - 1][n - 1];
    return 0;
}