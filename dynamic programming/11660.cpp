#include <iostream>
using namespace std;
int arr[1025][1025];
int dp[1025][1025];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    int x_1, x_2, y_1, y_2;
    for(int i = 1; i <= m; i++){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cout << dp[x_2][y_2] - dp[x_1 - 1][y_2] - dp[x_2][y_1 - 1] + dp[x_1 - 1][y_1 - 1] << "\n";
    }
    return 0;
}