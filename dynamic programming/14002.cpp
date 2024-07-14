#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int dp[1001];
int arr[1001];
int idx[1001];
vector<int> ans;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    int sum = 0;
    int start = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    idx[i] = j;
                }
            }
            else if(arr[i] == arr[j])
                dp[i] = dp[j];
        }
        if(sum < dp[i]){
            sum = dp[i];
            start = i;
        }
    }
    cout << sum << "\n";
    while(start > 0){
        int tmp = arr[start];
        ans.push_back(tmp);
        start = idx[start];
    }
    
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
