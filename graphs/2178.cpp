#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int n, m, cnt = 0;
bool visited[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int maze[102][102];
int res[102][102];

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty()){
        pair<int, int> tmp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int cx = tmp.first + dx[i];
            int cy = tmp.second + dy[i];
            if(maze[cx][cy] && cx > 0 && cx <= n && cy > 0 && cy <= m){
                if(!visited[cx][cy]){
                    q.push(make_pair(cx, cy));
                    visited[cx][cy] = true;
                    res[cx][cy] = res[tmp.first][tmp.second] + 1;
                }
            }
        }
    }
}

int main(){
    string str;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str;
        for(int j = 1; j <= m; j++){
            maze[i][j] = str[j - 1] - '0';
        }
    }
    bfs(1, 1);
    cout << res[n][m] + 1;
    return 0;
}