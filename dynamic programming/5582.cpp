#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    vector<vector<int>> dp(s2.size(), vector<int>(s1.size(), 0));
    for (int i = 0; i < s2.size(); i++) {
        for (int j = 0; j < s1.size(); j++) {
            if (s2[i] == s1[j]) {
                dp[i][j] = 1;
                if (i >= 1 && j >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}
