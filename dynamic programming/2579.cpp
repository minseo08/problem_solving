#include <iostream>
#include <algorithm>
using namespace std;
int arr[301];
int dp[301];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
    }
    cout << dp[n];
    return 0;
}