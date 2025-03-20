#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
long long dp[101][21];

int main(){
    int n, ans;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    cin >> ans;
    dp[0][arr[0]]++;
    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j <= 20; j++){
            if(dp[i - 1][j - arr[i]] > 0 && j - arr[i] >= 0)
                dp[i][j] += dp[i - 1][j - arr[i]];
            if(dp[i - 1][j + arr[i]] > 0 && j + arr[i] <= 20)
                dp[i][j] += dp[i - 1][j + arr[i]];
        }
    }
    cout << dp[n - 2][ans];
    return 0;
}