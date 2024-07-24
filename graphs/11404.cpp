#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int dp[101][101];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INF;
            }
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }
    for(int a = 1; a <= n; a++){
        for(int b = 1; b <= n; b++){
            for(int c = 1; c <= n; c++){
                dp[b][c] = min(dp[b][a] + dp[a][c], dp[b][c]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == INF){
                cout << 0 << " ";
            }
            else{
                cout << dp[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}