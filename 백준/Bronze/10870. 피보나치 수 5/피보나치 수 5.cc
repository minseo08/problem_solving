#include <iostream>
#include <algorithm>
using namespace std;
int n;

long long fib(int num){
    if(num == 1)
        return 0;
    if(num == 2)
        return 1;
    return fib(num - 2) + fib(num - 1);
}


int main(){
    cin >> n;
    cout << fib(n + 1);
    return 0;
}