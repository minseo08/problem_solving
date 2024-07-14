#include <iostream>
#include <cstring>
using namespace std;
int t, n, m, k;
int ground[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[51][51];

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(!visited[cx][cy] && ground[cx][cy] && cx >= 0 && cx < m && cy >= 0 && cy < n){
            visited[cx][cy] = true;
            dfs(cx, cy);
        }
    }
}

int main(){
    cin >> t;
    for(int a = 0; a < t; a++){
        cin >> m >> n >> k;
        int cnt = 0;
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            ground[x][y] = 1;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ground[i][j] && !visited[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << "\n";
        memset(ground, 0, sizeof(ground));
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}