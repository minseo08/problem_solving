#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    vector<int> dp[9]; //N의 사용횟수 별 계산 결과
    
    for(int i = 1; i <= 8; i++){
        int tmp = 0;
        for(int j = 0; j < i; j++){
            tmp += N * pow(10, j); 
        }
        dp[i].push_back(tmp);
    }
    
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 0; k < dp[j].size(); k++){
                for(int l = 0; l < dp[i - j].size(); l++){
                    dp[i].push_back(dp[j][k] + dp[i - j][l]);
                    if(dp[j][k] > dp[i - j][l]){
                        dp[i].push_back(dp[j][k] - dp[i - j][l]);
                    }
                    dp[i].push_back(dp[j][k] * dp[i - j][l]);
                    if(dp[j][k] >= dp[i - j][l]){
                        dp[i].push_back(dp[j][k] / dp[i - j][l]);
                    }
                }
            }
        }
    }
    
    for(int i = 1; i <= 8; i++){
        for(int j = 0; j < dp[i].size(); j++){
            if(dp[i][j] == number)
                return i;
        }
    }
    return -1;
}