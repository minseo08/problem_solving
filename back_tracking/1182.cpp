#include <iostream>
using namespace std;
int arr[21];
int s, n;
int cnt = 0;
void func(int num, int sum){
    sum += arr[num];
    if(sum == s){
        cnt++;
    }
    for(int i = num + 1; i < n; i++){
        func(i, sum);
    }
}

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        func(i, 0);
    }
    cout << cnt;
    return 0;
}