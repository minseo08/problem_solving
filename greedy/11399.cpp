#include <iostream>
#include <algorithm>

using namespace std;
int arr[1001];

int main(){
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++){
        sum += arr[i] * (n - i);
    }
    cout << sum;
    return 0;
}