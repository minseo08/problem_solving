#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
__uint128_t dp[101][101];

__uint128_t comb(int n, int m){
    //cout << n << " " << m << "\n";
    if(n == m || m == 0)
        dp[n][m] = 1;
    if(dp[n][m] != 0)
        return dp[n][m];
    else
        dp[n][m] = comb(n - 1, m) + comb(n - 1, m - 1);
    return dp[n][m];
}

int main(){
    int n, m;
    vector<int> vec;
    cin >> n >> m;
    __uint128_t tmp = comb(n, m);

    while(tmp){
        vec.push_back(tmp % 10);
        tmp /= 10;
    }
    for(int i = vec.size() - 1; i >= 0; i--)
        cout << vec[i];
    return 0;
}