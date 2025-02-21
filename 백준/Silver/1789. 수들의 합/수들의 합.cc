#include <iostream>
using namespace std;

int main(){
    long long s;
    cin >> s;
    long long i = 0;
    while(s >= 0){
        i++;
        s -= i;
    }
    cout << i - 1;
    return 0;
}