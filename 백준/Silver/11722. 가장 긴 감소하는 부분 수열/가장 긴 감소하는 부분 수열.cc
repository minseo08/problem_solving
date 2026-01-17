#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = n - 1; i >= 0; i--){
        dp[i]++;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }
    sort(dp, dp + n);
    cout << dp[n - 1];
    return 0;
}