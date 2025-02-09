#include <iostream>
#include <algorithm>
#define LOTTO 6
using namespace std;
int arr[51];
int res[51];

void comb(int a, int cnt, int n){
    if(cnt == LOTTO){
        for(int i = 0; i < cnt; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    for(int i = a; i < n; i++){
        res[cnt] = arr[i];
        comb(i + 1, cnt + 1, n);
    }
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        comb(0, 0, n);
        cout << "\n";
    }
    return 0;
}