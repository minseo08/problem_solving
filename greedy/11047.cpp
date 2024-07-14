#include <iostream>
using namespace std;

int main(){
    int n, k;
    int arr[11];
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sum = 0;
    for(int i = n - 1; i >= 0; i--){
        sum += k / arr[i];
        k %= arr[i];
    }
    cout << sum;
    return 0;
}