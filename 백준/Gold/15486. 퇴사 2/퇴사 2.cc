#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[1500001];
int dp[1500001];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    int curr = 0;
    for(int i = 1; i <= n + 1; i++){
        curr = max(curr, dp[i]);
        if(i + arr[i].first > n + 1)
            continue;
        dp[i + arr[i].first] = max(dp[i + arr[i].first], curr + arr[i].second);
    }
    cout << dp[n + 1];
    return 0;
}