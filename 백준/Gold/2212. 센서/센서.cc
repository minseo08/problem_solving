#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];

int main(){
    int n, k;
    long long sum = 0;
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 1; i <= n; i++){
        arr[i - 1] = arr[i] - arr[i - 1];
    }
    sort(arr , arr + n - 1);
    for(int i = 0; i < n - k; i++){
        sum += arr[i];
    }
    cout << sum;
    return 0;
}