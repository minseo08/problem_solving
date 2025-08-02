#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
int cnt = 0;

void dfs(int x, int y, int rain){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] > rain){
            if(!visited[nx][ny]){
                dfs(nx, ny, rain);
            }
        }
    }
}

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
}

int main(){
    cin >> n;
    int m = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            m = max(arr[i][j], m);
        }
    }
    for(int k = 0; k <= m; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] || arr[i][j] <= k)
                    continue;
                dfs(i, j, k);
                cnt++;
            }
        }
        res = max(res, cnt);
        init();
        cnt = 0;
    }
    cout << res;
    return 0;
}