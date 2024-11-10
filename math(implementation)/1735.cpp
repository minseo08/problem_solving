#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    int a, b, c, d;
    for(int i = 0; i < 2; i++){
        cin >> a >> b >> c >> d;
    }
    int m = b * d / gcd(b, d);
    int n = a * (m / b) + c * (m / d);
    int k = gcd(m, n);
    cout << n / k << " " << m / k;
    
    return 0;
}