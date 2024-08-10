#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 987654321
int dp[100001][7];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < 7; j++){
            dp[i][j] = MAX;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= str.size(); i++){
        dp[i][1] = min({dp[i - 1][0] + (str[i - 1] != 'B'), dp[i - 1][1] + (str[i - 1] != 'B'), dp[i - 1][6] + (str[i - 1] != 'B')});
        dp[i][2] = dp[i - 1][1] + (str[i - 1] != 'A');
        dp[i][3] = dp[i - 1][2] + (str[i - 1] != 'N');
        dp[i][4] = dp[i - 1][3] + (str[i - 1] != 'A');
        dp[i][5] = min(dp[i - 1][4] + (str[i - 1] != 'N'), dp[i - 1][6] + (str[i - 1] != 'N'));
        dp[i][6] = dp[i - 1][5] + (str[i - 1] != 'A');
    }
    cout << dp[str.size()][6];
    return 0;
}