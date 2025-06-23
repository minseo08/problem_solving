#include <iostream>
using namespace std;
int n, sum = 0;
int col[16];
bool promise(int lev){
    for(int i = 0; i < lev; i++){
        if(col[i] == col[lev] || abs(col[lev] - col[i]) == lev - i)
            return false;
    }
    return true;
}
void nqueen(int cur){
    if(cur == n)
        sum++;
    else{
        for(int i = 0; i < n; i++){
            col[cur] = i;
            if(promise(cur)){
                nqueen(cur + 1);
            }
        }
    }
}

int main(){
    cin >> n;
    nqueen(0);
    cout << sum;
    return 0;
}