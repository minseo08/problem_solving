#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
char arr[6][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[6][6];
int r, c, k;
int res;

void dfs(int x, int y, int cnt){
    visited[x][y] = true;
    if(x == 0 && y == c - 1){
        if(cnt == k){
            res++;
            return;
        }
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c && arr[nx][ny] != 'T' && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx, ny, cnt + 1);
            visited[nx][ny] = false;
        }
    }
    return;
}

int main(){
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }
    dfs(r - 1, 0, 1);
    cout << res;
    return 0;
}