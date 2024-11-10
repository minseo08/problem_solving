#include <iostream>
#include <algorithm>
using namespace std;
int arr[5000][5000];
int a, b, c;

void func(int x, int y, int sz){
    int num = arr[x][y];
    bool cut = false;
    for(int i = x; i < x + sz; i++){
        for(int j = y; j < y + sz; j++){
            if(arr[i][j] != num){
                cut = true;
                break;
            }
        }
    }
    if(cut){
        int tmp = sz / 3;
        func(x, y, tmp);
        func(x, y + tmp, tmp);
        func(x, y + tmp + tmp, tmp);
        func(x + tmp, y, tmp);
        func(x + tmp, y + tmp, tmp);
        func(x + tmp, y + tmp + tmp, tmp);
        func(x + tmp + tmp, y, tmp);
        func(x + tmp + tmp, y + tmp, tmp);
        func(x + tmp + tmp, y + tmp + tmp, tmp);
    }
    else{
        if(num == -1)
            a++;
        else if(num == 0)
            b++;
        else if(num == 1)
            c++;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    func(0, 0, n);
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    return 0;
}