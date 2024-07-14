#include <iostream>
#include <algorithm>
using namespace std;
int sosu[1000000] = { 1, 1, };

int main() {
    int n;
    for(int i = 2; i < 1000000; i++){
        for(int j = 2; i * j < 1000000; j++){
            sosu[i * j] = 1;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, cnt = 0;
        cin >> a;
        for(int j = 0; j < a; j++){
            if(sosu[j] == 0 && sosu[a - j] == 0){
                if(j == a - j)
                    cnt++;
                cnt++;
            }
        }
        cout << cnt / 2 << "\n";
    }
    return 0;
}