#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, k;
int graph[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> res;
int cnt;


void dfs(int x, int y){
    cnt++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < m && ny >= 0 && ny < n && !graph[nx][ny]){
            graph[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
    return;
}

int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        int x_1, y_1, x_2, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for(int j = x_1; j < x_2; j++){
            for(int l = y_1; l < y_2; l++){
                graph[l][j] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!graph[i][j]){
                dfs(i, j);
                res.push_back(cnt);
                cnt = 0;
            }
        }
    }
    cout << res.size() << "\n";
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++){
        if(res[i] > 1)
            cout << res[i] - 1 << " ";
        else
            cout << res[i] << " ";
    }
    return 0;
}