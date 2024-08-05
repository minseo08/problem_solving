#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, q;
    string str = "";
    cin >> q >> m;
    int a = 1;
    int b = 1;
    while(1){
        str += to_string(a);
        int tmp = (a + b) % m;
        a = b;
        b = tmp;
        if(a == 1 && b == 1){
            break;
        }
    }
    for(int i = 0; i < q; i++){
        long long x;
        cin >> x;
        cout << str[(x - 1) % (long long)str.length()] << "\n";
    }
    return 0;
}