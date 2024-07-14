#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    while(1){
        int r = a % b;
        if(r == 0)
            break;
        a = b;
        b = r;
    }
    return b;
}
int main() {
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cout << a * b / gcd(a, b) << "\n";
    }
    return 0;
}