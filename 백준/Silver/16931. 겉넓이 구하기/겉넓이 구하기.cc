#include <iostream>
using namespace std;
int n, m;
int arr[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = 0;
    cin >> n >> m;
    sum = 2 * n * m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= m; y++){
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(arr[x][y] > arr[nx][ny])
                    sum += (arr[x][y] - arr[nx][ny]);
            }
        }
    }
    cout << sum << "\n";

} 