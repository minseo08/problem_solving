#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
string arr[190];
int res[190][190];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        int nx, ny;
        for(int i = 0; i < 4; i++){
            nx = tx + dx[i];
            ny = ty + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == '0'){
                if(!res[nx][ny]){
                    res[nx][ny] = res[tx][ty] + 1;
                    q.push({nx, ny});
                }
                else{
                    if(res[nx][ny] > res[tx][ty] + 1){
                        res[nx][ny] = res[tx][ty] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, arr[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '1'){
                bfs(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}