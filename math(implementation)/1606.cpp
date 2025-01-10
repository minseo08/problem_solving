#include <iostream>
using namespace std;

long long func(int x, int y){
    if(y == 0){
        if(x == 0)
            return 1;
        else
            return func(x - 1, 0) + 6 * x;
    }
    else
        return func(x + y - 1, 0) + y;
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << func(x, y);
    return 0;
}