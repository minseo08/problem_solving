#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int res = -10000001;
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for(int i = k; i <= n; i++){
        res = max(res, arr[i] - arr[i - k]);
    }
    cout << res;
    return 0;
}