#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][15];

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int k, n;
        cin >> k >> n;
        for(int a = 0; a <= k; a++){
            for(int b = 1; b <= n; b++){
                if(a == 0)
                    arr[a][b] = b;
                else if(b == 1)
                    arr[a][b] = 1;
                else{
                    arr[a][b] = arr[a - 1][b] + arr[a][b - 1];
                }
            }
        }
        cout << arr[k][n] << "\n";
    }
    return 0;
}

// 1 4 10 20 35 ...
// 1 3 6 10 15 ...
// 1 2 3 4 5 6 7 8