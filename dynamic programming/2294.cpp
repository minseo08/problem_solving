#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
int value_case[10001];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= k; i++){
        value_case[i] = k + 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = arr[i]; j <= k; j++){
            value_case[j] = min(value_case[j - arr[i]] + 1, value_case[j]) ;
        }
    }
    if(value_case[k] == k + 1)
        cout << -1;
    else
        cout << value_case[k];
        
    return 0;
}