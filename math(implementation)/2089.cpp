#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    if (n == 0)
        cout << '0';
    while(n != 0){
        if(n % -2 == 0){
            str += '0';
            n /= -2;
        }
        else{
            str += '1';
            n = (n - 1) / -2;
        }
    }
    reverse(str.begin(), str.end());
    cout << str << "\n";
    return 0;
}