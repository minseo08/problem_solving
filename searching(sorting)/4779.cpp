#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void func(int cur){
    if(cur == 1){
        cout << "-";
        return;
    }
    int a = (cur / 3);
    func(a);
    for(int i = 0; i < a; i++)
        cout << " ";
    func(a);
    return;
}

int main(){
    int n;
    while(cin >> n){
        int k = pow(3, n);
        func(k);
        cout << "\n";
    }
    return 0;
}