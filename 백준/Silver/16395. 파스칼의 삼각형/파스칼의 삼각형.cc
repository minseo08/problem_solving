#include <iostream>
#include <algorithm>
using namespace std;
int arr[31][31];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1)
                arr[i][j] = 1;
            else{
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
    cout << arr[n][k];
    
    return 0;
}