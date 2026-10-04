#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[101][101];
int arr[101][101];
int cnt = 0;

void dfs(int x, int y, int tx, int ty, int maps[101][101]){
    visited[x][y] = true;
    cnt += maps[x][y];
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < tx && ny < ty && !visited[nx][ny] && maps[nx][ny]){
            dfs(nx, ny, tx, ty, maps);
        }
    }
}

vector<int> solution(vector<string> maps) {
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(maps[i][j] != 'X')
                arr[i][j] = maps[i][j] - '0';
            else
                arr[i][j] = 0;
        }
    }
    vector<int> answer;
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(!visited[i][j] && arr[i][j]){
                dfs(i, j, maps.size(), maps[0].size(), arr);
                if(cnt > 0)
                    answer.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(!answer.size())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    return answer;
}