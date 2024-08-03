#include <iostream>
using namespace std;

int arr[10001];

int main(){
    int n, m;
    int sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int start = -1;
    int end = -1;
    int res = 0;
    while(end < n){
        if(sum < m){
            end++;
            sum += arr[end];
        }
        else if(sum >= m){
            if(sum == m){
                res++;
            }
            start++;
            sum -= arr[start];
        }
    }
    cout << res;
    return 0;
}