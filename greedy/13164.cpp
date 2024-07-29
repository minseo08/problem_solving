#include <iostream>
#include <algorithm>
using namespace std;
int arr[300001];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int res = arr[n - 1] - arr[0];
    for(int i = n - 1; i >= 1; i--){
        arr[i] = arr[i] - arr[i - 1];
    }
    arr[0] = 0;
    sort(arr, arr + n);
    for(int i = n - 1; k > 1; i--){
        k--; //k-1만큼 경계 추가
        res -= arr[i];//경계 추가시에 차이만큼 비용은 제외됨
    }
    cout << res;
    return 0;
}