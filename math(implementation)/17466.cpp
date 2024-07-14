#include <iostream>
using namespace std;

int main(){
    int n, p;
    long long res = 1;
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        res = (res * (i % p)) % p;
    }
    cout << res;
    return 0;
}