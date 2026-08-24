#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;
bool coord[102][102];
bool visited[102][102];
bool block[102][102];
int result[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int curr_x, int curr_y, int dest_x, int dest_y, int cnt){
    result[curr_x][curr_y] = min(result[curr_x][curr_y], cnt);
    if(curr_x == dest_x && curr_y == dest_y){
        return;
    }
    visited[curr_x][curr_y] = true;
    for(int i = 0; i < 4; i++){
        int nx = curr_x + dx[i];
        int ny = curr_y + dy[i];
        if(coord[nx][ny] && !visited[nx][ny]){
            dfs(nx, ny, dest_x, dest_y, cnt + 1);
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for(int i = 0; i < rectangle.size(); i++){
        for(int j = rectangle[i][0]; j <= rectangle[i][2]; j++){
            if(!block[j * 2][rectangle[i][1] * 2]){
                coord[j * 2][rectangle[i][1] * 2] = true;
            }
            if(!block[j * 2 + 1][rectangle[i][1] * 2]){
                coord[j * 2 + 1][rectangle[i][1] * 2] = true;
            }
            coord[rectangle[i][2] * 2 + 1][rectangle[i][1] * 2] = false;
        }
        for(int j = rectangle[i][1]; j <= rectangle[i][3]; j++){
            if(!block[rectangle[i][0] * 2][j * 2]){
                coord[rectangle[i][0] * 2][j * 2] = true;
            }
            if(!block[rectangle[i][0] * 2][j * 2 + 1]){
                coord[rectangle[i][0] * 2][j * 2 + 1] = true;
            }
            coord[rectangle[i][0] * 2][rectangle[i][3] * 2 + 1] = false;   
        }
        for(int j = rectangle[i][1]; j <= rectangle[i][3]; j++){
            if(!block[rectangle[i][2] * 2][j * 2]){
                coord[rectangle[i][2] * 2][j * 2] = true;
            }
            if(!block[rectangle[i][2] * 2][j * 2 + 1]){
                coord[rectangle[i][2] * 2][j * 2 + 1] = true;
            }
            coord[rectangle[i][2] * 2][rectangle[i][3] * 2 + 1] = false;
        }
        for(int j = rectangle[i][0]; j <= rectangle[i][2]; j++){
            if(!block[j * 2][rectangle[i][3] * 2]){
                coord[j * 2][rectangle[i][3] * 2] = true;
            }
            if(!block[j * 2 + 1][rectangle[i][3] * 2]){
                coord[j * 2 + 1][rectangle[i][3] * 2] = true;
            }
            coord[rectangle[i][2] * 2 + 1][rectangle[i][3] * 2] = false;
        }
        
        for(int j = rectangle[i][0]; j <= rectangle[i][2]; j++){
            if(j == rectangle[i][2])
                continue;
            for(int k = rectangle[i][1]; k <= rectangle[i][3]; k++){
                if(k == rectangle[i][3])
                    continue;
                block[j * 2][k * 2] = true;
                block[j * 2 + 1][k * 2] = true;
                block[j * 2][k * 2 + 1] = true;
                block[j * 2 + 1][k * 2 + 1] = true;
            }
        }
        
        for(int j = rectangle[i][0]; j <= rectangle[i][2]; j++){
            if(j == rectangle[i][2])
                continue;
            for(int k = rectangle[i][1]; k <= rectangle[i][3]; k++){
                if(k == rectangle[i][3])
                    continue;
                if(j != rectangle[i][0] && k != rectangle[i][1])
                    coord[j * 2][k * 2] = false;
                if(j != rectangle[i][0])
                    coord[j * 2][k * 2 + 1] = false;
                if(k != rectangle[i][1])
                    coord[j * 2 + 1][k * 2] = false;
                coord[j * 2 + 1][k * 2 + 1] = false;
            }
        }
    }
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            result[i][j] = INF;
        }
    }

    
    dfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2, 1);
    // for(int j = 18; j >= 0; j--){
    //     for(int k = 0; k <= 18; k++){
    //         cout << result[k][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
    int answer = result[itemX * 2][itemY * 2] / 2;
    return answer;
}