#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, cut;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long max = arr[n - 1];
    long long min = 0;
    long long res = 0;
    while(max >= min){
        long long sum = 0;
        cut = (max + min) / 2;
        for(int i = 0; i < n; i++){
            if(arr[i] >= cut)
                sum += arr[i] - cut; 
        }
        if(sum >= m){
            res = cut;
            min = cut + 1;
        }
        else if (sum < m){
            max = cut - 1;
        }
    }
    cout << res;
}