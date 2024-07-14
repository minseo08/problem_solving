#include <iostream>
#include <cstdlib>
using namespace std;
int gcd(int a, int b){
    if(a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    if(a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int main(){
    int n, s, a;
    cin >> n >> s;
    int arr[n];
    for(int i = 0; i < n; i++){
        if(i == 0){
            cin >> a;
            arr[i] = abs(a - s);
        }
        else{
            cin >> a;
            arr[i] = abs(a - s);
            arr[i] = gcd(arr[i - 1], arr[i]);
        }
    }
    cout << arr[n - 1];
    return 0;
}