#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    int sum = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = arr[i];
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]){
                if(dp[i] < dp[j] + arr[i]){
                    dp[i] = dp[j] + arr[i];
                }
            }
        }
        sum = max(sum, dp[i]);
    }
    cout << sum;
    return 0;
}
