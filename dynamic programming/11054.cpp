#include <iostream>
using namespace std;
int arr[1000];
int dp_l[1000];
int dp_r[1000];

int main() {
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        dp_l[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && dp_l[i] < dp_l[j] + 1){
                dp_l[i]  = dp_l[j] + 1;
            }
        }
    }
    for(int i = n - 1; i >= 0; i--){
        dp_r[i] = 1;
        for(int j = n - 1; j > i; j--){
            if(arr[j] < arr[i] && dp_r[i] < dp_r[j] + 1){
                dp_r[i]  = dp_r[j] + 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(res < dp_l[i] + dp_r[i] - 1)
            res = dp_l[i] + dp_r[i] - 1;
    }
    cout << res;
    return 0;
}