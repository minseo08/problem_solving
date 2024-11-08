#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int arr[401][401];
int v, e;

void floyd(){
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            for(int k = 1; k <= v; k++){
                if(arr[j][k] > arr[j][i] + arr[i][k])
                    arr[j][k] = arr[j][i] + arr[i][k];
            }
        }
    }
}

int main(){
    cin >> v >> e;
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            if(i != j)
                arr[i][j] = INF;
        }
    }
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;        
    }
    floyd();
    int res = INF;
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            if(i != j)
                res = min(res, arr[i][j] + arr[j][i]);
        }
    }
    if(res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}