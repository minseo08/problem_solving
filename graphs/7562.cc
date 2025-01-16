#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visited[301][301];
int arr[301][301];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int s, a, b, e_x, e_y;
queue<pair<int, int>> q;

void bfs(int s_x, int s_y){
    q.push({s_x, s_y});
    visited[s_x][s_y] = true;
    while(!q.empty()){
        int t_x = q.front().first;
        int t_y = q.front().second;
        q.pop();
        if(t_x == e_x && t_y == e_y){
            cout << arr[t_x][t_y] << "\n";
            break;
        }
        
        for(int i = 0; i < 8; i++){
            int nx = t_x + dx[i];
            int ny = t_y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < s && ny < s && !visited[nx][ny]){
                q.push({nx, ny});
                visited[nx][ny] = true;
                arr[nx][ny] = arr[t_x][t_y] + 1;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s;
        cin >> a >> b;
        cin >> e_x >> e_y;
        bfs(a, b);
        while(!q.empty())
            q.pop();
        for(int i = 0; i < 301; i++){
            for(int j = 0; j < 301; j++){
                arr[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
    return 0;
}