#include <iostream>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int arr[501][501];
int dp[501][501];
bool visited[501][501];

int dfs(int y, int x){
    if(x == n && y == m){
        return 1;
    }
    if (!visited[y][x]) {
        visited[y][x] = true;
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (arr[ny][nx] != 0 && arr[y][x] > arr[ny][nx]) {
                dp[y][x] += dfs(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    cout << dfs(1, 1);

    return 0;
}