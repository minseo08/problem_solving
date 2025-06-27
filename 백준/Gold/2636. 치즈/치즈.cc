#include <iostream>
#include <queue>
using namespace std;
int graph[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int n, m, cnt = 0;
int res = 0;

void bfs(int x, int y){
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        cnt++;
        vector<pair<int, int>> vec;
        while(!q.empty()){
            int tx = q.front().first;
            int ty = q.front().second;
            //cout << tx << " " << ty << "\n";
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = tx + dx[i];
                int ny = ty + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !graph[nx][ny] && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
                else if(nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    vec.push_back({nx, ny});
                }
            }
        }
        for(int i = 0; i < vec.size(); i++){
            //cout << vec[i].first << " " << vec[i].second << "\n";
            q.push({vec[i].first, vec[i].second});
        }
        if(vec.size())
            res = vec.size();
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    bfs(0, 0);
    cout << cnt - 1 << "\n";
    cout << res;
    return 0;
}