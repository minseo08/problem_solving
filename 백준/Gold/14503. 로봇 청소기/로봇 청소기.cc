#include <iostream>
#include <algorithm>
using namespace std;
bool check[51][51];
int wall[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;



int main(){
    int n, m;
    int r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> wall[i][j];
        }
    }
    bool flag = false;
    while(1){
        if(!check[r][c]){
            check[r][c] = true;
            cnt++;
        }
        for(int i = 0; i <= 4; i++){
            if(i == 4){
                if(wall[r + dx[(d + 2) % 4]][c + dy[(d + 2) % 4]]){
                    flag = true;
                }
                else{
                    r += dx[(d + 2) % 4];
                    c += dy[(d + 2) % 4];
                    break;
                }
            }
            d = (d + 3) % 4;
            int nr = r + dx[d];
            int nc = c + dy[d];
            if(!wall[nr][nc] && !check[nr][nc] && nr >= 0 && nr < n && nc >= 0 && nc < m){
                r = nr;
                c = nc;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    cout << cnt;

    return 0;
}