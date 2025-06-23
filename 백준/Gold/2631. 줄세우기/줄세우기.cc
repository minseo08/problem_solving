#include <iostream>
#include <algorithm>
using namespace std;
int arr[201];
int dp[201];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }    
    sort(dp, dp + n);
    cout << n - dp[n - 1];
    
    return 0;
}
// 1 2 2 1 3 1 2