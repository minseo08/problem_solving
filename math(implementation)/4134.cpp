#include <iostream>
#include <cmath>
using namespace std;

bool prime(long long n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long n;
        cin >> n;
        if(n == 0 || n == 1){
            cout << "2" << "\n";
            continue;
        }
        while(!prime(n)){
            n++;
        }
        cout << n << "\n";
    }    
    return 0;
}