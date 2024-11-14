#include <iostream>
#include <algorithm>
using namespace std;
int arr1[101][101];
int arr2[101][101];
int res[101][101];

int main(){
    int n, m, k;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> arr1[i][j];
    }
    cin >> m >> k;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++)
            cin >> arr2[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            for(int k = 0; k < m; k++){
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}