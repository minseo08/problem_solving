#include <iostream>
#define INF 987654321
using namespace std;
int arr[100001];
int res = INF;

int main(){
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int st = 0;
    int ed = 0;
    int sum = arr[0];
    while(st <= ed && ed <= n){
        if(sum >= s){
            res = min(res, ed - st + 1);
            sum -= arr[st];
            st++;
        }
        else{
            ed++;
            sum += arr[ed];
        }
    }
    if(res == INF)
        cout << 0;
    else
        cout << res;
    return 0;
}