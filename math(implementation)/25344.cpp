#include <iostream>
using namespace std;

int cdg(int a, int b){
    if(b > a){
        int tmp = b;
        b = a;
        a = tmp;
    }
    int r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long csg = 1;
    cin >> n;
    for(int i = 0; i < n - 2; i++){
        int a;
        cin >> a;
        csg = csg * a / cdg(csg, a);
    }
    cout << csg;
    return 0;
}