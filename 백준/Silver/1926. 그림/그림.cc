#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[501][501];
bool visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int cnt = 0;

void dfs(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny]){
            dfs(nx, ny);
        }
    }
    
}

int main(){
    cin >> n >> m;
    vector<int> res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] && !visited[i][j]){
                dfs(i, j);
                res.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(res.empty()){
        cout << 0 << "\n" << 0;
        return 0;
    }
    sort(res.begin(), res.end());
    int r = res.size();
    cout << r << "\n";
    cout << res[r - 1];
    return 0;
}