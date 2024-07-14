#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int d = a % c;
    int e = b % c;
    cout << (a + b) % c << endl;
    cout << (d + e) % c << endl;
    cout << (a * b) % c << endl;
    cout << (d * e) % c << endl;
    return 0;
}