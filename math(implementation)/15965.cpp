#include <iostream>
using namespace std;
#define MAX 7500001

int main(){
    int k, cnt = 0;
    bool arr[MAX] = { 0, };
    cin >> k;
    arr[0] = true;
    arr[1] = true;
    for(int i = 2; i <= 500000; i++){
        for(int j = 2; i * j <= MAX - 1; j++){
            arr[i * j] = true;
        }
    }
    for(int i = 0; i <= MAX - 1; i++){
        if(!arr[i]){
            cnt++;
            if(cnt == k)
                cout << i;
        }
    }
    
    return 0;
}