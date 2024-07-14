#include <iostream>
using namespace std;
int arr[101];
int value_case[10001] = { 1, };

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = arr[i]; j <= k; j++){
            value_case[j] += value_case[j - arr[i]];
        }
    }
    cout << value_case[k];
}