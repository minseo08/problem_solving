#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int m, n;
int res = 0;
bool is_zero = false;

void bfs(void){
    while(!q.empty()){
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if(arr[nx][ny] == 0 && nx >= 0 && nx < n && ny >= 0 && ny < m){//범위 내에서로 한정
                arr[nx][ny] = arr[fx][fy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1)
                q.push({i, j});
        }
    }
    bfs();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                is_zero = true;
                break;
            }
            res = max(res, arr[i][j]);
            //cout << arr[i][j] << " ";
        }
        if(is_zero)
            break;
    }
    if(is_zero){
        cout << -1;
        return 0;
    }
    cout << res - 1;
    return 0;
}