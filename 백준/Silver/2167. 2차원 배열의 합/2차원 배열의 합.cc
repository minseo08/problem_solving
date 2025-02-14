#include <iostream>
using namespace std;
int arr[301][301];
int dp[301][301];

int main(){
    int n, m, k, sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    cin >> k;
    for(int p = 0; p < k; p++){
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1] << "\n";
    }
    return 0;
}