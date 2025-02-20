#include <iostream>
#include <algorithm>
using namespace std;
int arr[16][2];
int dp[16];

int main(){
    int n, max_pr = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i][0] >> arr[i][1];
        max_pr = max(dp[i], max_pr);
        dp[i] = max_pr;
        if(i + arr[i][0] <= n + 1){
            dp[i + arr[i][0]] = max(dp[i] + arr[i][1], dp[i + arr[i][0]]);
        }
    }
    cout << max(dp[n], dp[n + 1]);
    return 0;
}