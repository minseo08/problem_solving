#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> water[51];
double dp[51] = { 0.0, 100.0, };

bool compare(double a, double b){
    return a > b;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v, w;
        cin >> v >> w;
        water[v].push_back(w);
    }
    for(int i = 1; i <= n; i++){
        double a = dp[i] / (double)water[i].size();
        for(int j = 0; j < water[i].size(); j++){
            dp[water[i][j]] += a;
            dp[i] = 0;
        }
    }
    sort(dp, dp + n + 1, compare);
    cout.precision(15);
    cout << fixed << dp[0];
        
    return 0;
}