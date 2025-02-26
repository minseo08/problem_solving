#include <iostream>
#define MAX 51
using namespace std;
int dh[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dw[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int w, h;
int arr[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int cur_h, int cur_w){
    visited[cur_h][cur_w] = true;
    for(int i = 0; i < 8; i++){
        int nh = cur_h + dh[i];
        int nw = cur_w + dw[i];
        if(nh >= 0 && nh < h && nw >= 0 && nw < w && arr[nh][nw] && !visited[nh][nw]){
            dfs(nh, nw);
        }
    }
}

int main(){
    while(cin >> w >> h){
        if(w == 0 && h == 0){
            break;
        }
        int cnt = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!visited[i][j] && arr[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                arr[i][j] = 0;
                visited[i][j] = false;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}