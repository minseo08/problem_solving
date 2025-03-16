#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];

int main(){
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int tmp = arr[0];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] < tmp + l){
            continue;
        }
        cnt++;
        tmp = arr[i];
    }
    cnt++;
    cout << cnt;
    return 0;
}