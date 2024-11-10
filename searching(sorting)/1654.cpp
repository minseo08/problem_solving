#include <iostream>
#include <algorithm>
using namespace std;
long long arr[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    long long m = 0;
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> arr[i];
        m = max(m, arr[i]);
    }
    long long left = 1;
    long long right = m;
    long long res = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        int cur = 0;
        for(int i = 0; i < k; i++){
            cur += (arr[i] / mid);
        }
        if(cur >= n){
            left = mid + 1;
            res = max(mid, res);
        }
        else{
            right = mid - 1;
        }
    }
    cout << res;
    return 0;
}