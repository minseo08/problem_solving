#include <iostream>
#include <vector>
using namespace std;
char graph[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

void dfs(int x, int y){
    visited[x][y] = true;
    char curr = graph[x][y];
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && graph[nx][ny] == curr && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] == 'G'){
                graph[i][j] = 'R';
            }
            visited[i][j] = false;
        }
    }
    cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}