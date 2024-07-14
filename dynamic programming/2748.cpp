#include <iostream>
using namespace std;
#define MAX 91

long long arr[MAX];

int main(){
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= MAX; i++){
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    int n;
    cin >> n;
    cout << arr[n];
    return 0;
}