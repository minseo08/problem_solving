#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        long long res = 1;
        for(int j = 0; j < a; j++){
            res *= b - j;
            res /= (j + 1);
        }
        cout << res << "\n";
    }
    return 0;
}