#include <iostream>
using namespace std;

int main() {
    int a, b, r;
    cin >> a >> b;
    if(a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int mul = a * b;
    while(1){
        r = a % b;
        if(r == 0)
            break;
        else{
            a = b;
            b = r;
        }
    }
    cout << b << "\n" << mul / b;
    return 0;
}