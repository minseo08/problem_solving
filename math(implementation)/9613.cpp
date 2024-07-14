#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        long long cnt = 0;
        int arr[m];
        for(int j = 0; j < m; j++){
            cin >> arr[j];
        }
        for(int j = 0; j < m; j++){
            for(int k = 1; j + k < m; k++){
                cnt += gcd(arr[j], arr[j + k]);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}