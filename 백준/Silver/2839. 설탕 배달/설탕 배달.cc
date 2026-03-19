#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = n / 5;
    int cnt = 0;
    while(a >= 0){
        if((n - (5 * a)) % 3 == 0){
            cnt = a + (n - (5 * a)) / 3;
            cout << cnt;
            break;
        }
        else if(a == 0){
            cout << "-1";
            break;
        }
        a--;
    }
    return 0;
}
