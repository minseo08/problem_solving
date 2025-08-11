#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k;
int cnt;

void dfs(int x, int y){
    cnt++;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!visited[nx][ny]&& arr[nx][ny] && nx > 0 && nx <= n && ny > 0 && ny <= m){
            dfs(nx, ny);
        }
    }
}

int main(){
    cin >> n >> m >> k;
    priority_queue<int> res;
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] && !visited[i][j]){
                dfs(i, j);
                res.push(cnt);
                cnt = 0;
            }
        }
    }
    cout << res.top();
    
    return 0;
}