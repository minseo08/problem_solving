#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> vec;
int dp[501];

int main(){
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(vec[i].second > vec[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << n - res;
    
    return 0;
}