#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];

int main() {
    int n;
    int tmp = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i - 1] + arr[i] > arr[i])
            arr[i] = arr[i - 1] + arr[i];
    }
    sort(arr, arr + n);
    cout << arr[n - 1];
    return 0;
}