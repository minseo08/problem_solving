#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[100000][2];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    int res = arr[0];
    for(int i = 1; i < n; i++){
        dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        res = max(res, max(dp[i][0], dp[i][1]));
    }
    cout << res;
    return 0;
}