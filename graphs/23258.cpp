#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;
int dp[301][301][301];
int n, q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> dp[i][j][0];
            if(dp[i][j][0] == 0 && i != j){
                dp[i][j][0] = INF;
            }
        }
    }
    for(int c = 1; c <= n ; c++){
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                dp[a][b][c] = min(dp[a][b][c - 1], dp[a][c][c - 1] + dp[c][b][c - 1]);
            }
        }
    }
    for(int i = 0; i < q; i++){
        int c, s, e;
        cin >> c >> s >> e;
        if(dp[s][e][c - 1] == INF){
            cout << "-1" << "\n";
        }
        else{
            cout << dp[s][e][c - 1] << "\n";
        }
    }
    return 0;
}