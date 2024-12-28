#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
string arr[26];
bool visited[26][26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
vector<int> res;
int n;
int cnt = 0;

void bfs(int x, int y){
    q.push({x, y});
    int house = 0;
    while(!q.empty()){
        int tmp_x = q.front().first;
        int tmp_y = q.front().second;
        q.pop();
        visited[tmp_x][tmp_y] = true;
        for(int i = 0; i < 4; i++){
            int nx = tmp_x + dx[i];
            int ny = tmp_y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(arr[nx][ny] == '1' && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    house++;
                }
            }
        }
    }
    res.push_back(house);
    cnt++;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == '1' && !visited[i][j]){
                bfs(i, j);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << cnt << "\n";
    for(int i = 0; i < res.size(); i++){
        cout << res[i] + 1 << "\n";
    }
    return 0;
}