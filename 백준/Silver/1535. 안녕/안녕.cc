#include <iostream>
#include <algorithm>
using namespace std;
int L[21];
int J[21];
int dp[101];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> L[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> J[i];
    }
    //dp => 해당 체력만큼 사용한 경우의 최대 기쁨
    for(int i = 1; i <= n; i++){
        for(int j = 100; j > L[i]; j--){
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }
    cout << dp[100];
    return 0;
}