#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[101][101][101];

int main(){
    string str1, str2, str3;
    cin >> str1;
    cin >> str2;
    cin >> str3;
    str1 = '0' + str1;
    str2 = '0' + str2;
    str3 = '0' + str3;
    for(int i = 0; i < str1.size(); i++){
        for(int j = 0; j < str2.size(); j++){
            for(int k = 0; k < str3.size(); k++){
                if(i == 0 || j == 0 || k == 0){
                    dp[i][j][k] = 0;
                }
                else if(str1[i] == str2[j] && str2[j] == str3[k]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]),dp[i][j][k-1]);
                }
            }
        }
    }
    cout << dp[str1.size()-1][str2.size()-1][str3.size()-1];
    return 0;
}