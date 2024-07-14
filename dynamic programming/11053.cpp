#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int arr[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    sort(dp, dp + n);
    cout << dp[n - 1];
    return 0;
}