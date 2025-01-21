#include <iostream>
using namespace std;
int cnt_fib, cnt_dp;
int dp[41];

int fib(int n){
    if(n == 1 or n == 2){
        cnt_fib++;
        return 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int main(){
    int n;
    cin >> n;
    fib(n);
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; i++){
        cnt_dp++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << cnt_fib << " " << cnt_dp;
    return 0;
}