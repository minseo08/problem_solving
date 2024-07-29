#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int res = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] > res){
            break;
        }
        res += arr[i];
    }
    cout << res;
    return 0;
}