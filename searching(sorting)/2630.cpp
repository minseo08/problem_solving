#include <iostream>
using namespace std;
int arr[130][130];
int b = 0;
int w = 0;
void func(int x, int y, int num){
    int color = arr[x][y];
    bool cut = false;
    for(int i = x; i < x + num; i++){
        for(int j = y; j < y + num; j++){
            if(arr[i][j] != color){
                cut = true;
                break;
            }
        }
    }
    if(cut){
        func(x, y, num / 2);
        func(x, y + num / 2, num / 2);
        func(x + num / 2, y, num / 2);
        func(x + num / 2, y + num / 2, num / 2);
    }
    else{
        if(color == 1)
            b++;
        else
            w++;
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
    cout << w << "\n";
    cout << b << "\n";
    return 0;
}