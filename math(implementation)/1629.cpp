#include <iostream>
using namespace std;
int pow(int a, int b, int c){
    if (b == 1)
        return a % c;
    long long ret = pow(a, b / 2, c) % c;
    if (b % 2 == 0)
        return ret * ret % c;
    else
        return (ret * ret % c * a) % c;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << pow (a, b, c);
}