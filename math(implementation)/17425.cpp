#include <iostream>
#define MAX 1000000
using namespace std;

long long arr[MAX + 1] = { 0, };

int main(){
    for(int i = 1; i < MAX + 1; i++){
        for(int j = i; j < MAX + 1; j += i){
            arr[j] += i;
        }
    }
    for(int i = 1; i < MAX + 1; i++){
        arr[i] += arr[i - 1];
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cout << arr[a] << "\n";
    }
}