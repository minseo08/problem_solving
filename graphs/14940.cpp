#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int map[1001][1001];
int res[1001][1001];
bool visited[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    visited[x][y] = true;
    res[x][y] = 0;
    q.push(make_pair(x, y));
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int cx = tmp.first + dx[i];
            int cy = tmp.second + dy[i];
            if(cx >= 0 && cx < n && cy >=0 && cy < m && !visited[cx][cy] && map[cx][cy]){
                visited[cx][cy] = true;
                q.push(make_pair(cx, cy));
                res[cx][cy] = res[tmp.first][tmp.second] + 1;
            }
        }
    }
}

int main(){
    int sx, sy;
    cin >> n >> m;
    memset(res, -1, sizeof(res));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if (map[i][j] == 2){
                sx = i;
                sy = j;
            }
            if (map[i][j] == 0){
                res[i][j] = 0;
            }
        }
    }
    bfs(sx, sy);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}