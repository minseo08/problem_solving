#include <iostream>
using namespace std;
int cnt = 0;

void hanoi(int num, int s, int by, int d){
    if (num == 1){
        cout << s << " " << d << "\n";
    }
    else{
        hanoi(num - 1, s, d, by);
        cout << s << " " << d << "\n";
        hanoi(num - 1, by, s, d);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    hanoi(n, 1, 2, 3);
    return 0;
}