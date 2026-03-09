#include <iostream>
using namespace std;
int main() {
    int m, n;
    int a[10000] = { -1, };
    int j = 0;
    int sum = 0;
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                cnt++;
            }
        }
        if(cnt == 2){
            a[j] = i;
            j++;
            sum += i;
        }
    }
    if(a[0] == -1){
        cout << "-1" << endl;
    }
    else{
        cout << sum << endl;
        cout << a[0] << endl;
    }
    return 0;
}