#include <iostream>
#include <string>
using namespace std;
string video[64];

void func(int size, int y, int x){
    char curr = video[y][x];
    for (int i = y; i < y + size; i++){
        for (int j = x; j < x + size; j++){
            if (video[i][j] != curr){
                cout << '(';
                func(size / 2, y, x);
                func(size / 2, y, x + size / 2);
                func(size / 2, y + size / 2, x);
                func(size / 2, y + size / 2, x + size / 2);
                cout << ')';
                return;
            }
        }
    }

    cout << curr;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> video[i];
    }
    func(n, 0, 0);
    return 0;
}