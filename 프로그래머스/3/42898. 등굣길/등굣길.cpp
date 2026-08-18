#include <string>
#include <vector>
#include <iostream>

int dp[101][101];
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i = 0; i < puddles.size(); i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] < 0)
                continue;
            if(dp[i + 1][j] >= 0){
                dp[i + 1][j] += dp[i][j] % 1000000007;
            }
            if(dp[i][j + 1] >= 0){
                dp[i][j + 1] += dp[i][j] % 1000000007;
            }
        }
    }
    int answer = dp[n][m] % 1000000007;
    return answer;
}