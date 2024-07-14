#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];

int main(){
    int n, m;
    long long max, min, mid, res = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n); // 3 5 7
    max = 1000000000001;
    min = 1;
    while(min + 1 < max){
        long long sum = 0;
        mid = (max + min) / 2; // 40
        for(int i = 0; i < n; i++){
            sum += mid / arr[i]; // 8 + 5 + 13 = 26
        }
        if (sum >= m){
            res = mid;
            max = mid;
        }
        else{
            min = mid;
        }
    }
    cout << res;
}