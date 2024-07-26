#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long res = sqrt(n);
    if(res * res < n)
        res++;
    cout << res;
    return 0;
}