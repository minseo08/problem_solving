#include <iostream>
#include <vector>
using namespace std;
char arr[601][601];
bool visited[601][601];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, cnt = 0;

void dfs(int x, int y){
    if(arr[x][y] == 'P'){
        cnt++;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny] != 'X'){
            if(arr[nx][ny] == 'O' || arr[nx][ny] == 'P'){
                visited[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    int sx, sy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'I'){
                sx = i;
                sy = j;
            }
        }
    }
    dfs(sx, sy);
    if(cnt == 0)
        cout << "TT";
    else
        cout << cnt;
    return 0;
}