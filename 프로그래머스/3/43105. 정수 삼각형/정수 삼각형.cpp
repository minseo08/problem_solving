#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int dp[501][501];
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        for (int j = 0; j < triangle[i].size(); j++){
            dp[i][j] = max(dp[i - 1][j - 1] + triangle[i][j], dp[i][j]);
            dp[i][j] = max(dp[i - 1][j] + triangle[i][j], dp[i][j]);
            
        }
    }
    // for(int i = 0; i < triangle.size(); i++){
    //     for (int j = 0; j < triangle[i].size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int answer = 0;
    int len = triangle.size() - 1;
    for(int i = 0; i < triangle[len].size(); i++){
        answer = max(answer, dp[len][i]);
    }
    return answer;
}