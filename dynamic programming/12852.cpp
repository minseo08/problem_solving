#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];
int res[1000001];

int main(){
    arr[1] = 0;
    arr[2] = 1;
    res[1] = 0;
    res[2] = 1;
    int x;
    cin >> x;
    for(int i = 3; i <= x; i++){
        arr[i] = arr[i - 1] + 1;
        res[i] = i - 1;
        if(i % 2 == 0){
            if (arr[i / 2] + 1 < arr[i]){
                arr[i] = arr[i / 2] + 1;
                res[i] = i / 2;
            }
        }
        if(i % 3 == 0){
            if (arr[i / 3] + 1 < arr[i]){
                arr[i] = arr[i / 3] + 1;
                res[i] = i / 3;
            }
        }
    }
    cout << arr[x] << "\n";
    cout << x << " ";
    for(int i = x; i > 1; i = res[i]){
        cout << res[i] << " ";
    }
    
    return 0;
}