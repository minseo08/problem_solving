#include <iostream>
using namespace std;
#define MAX 5000000
int arr[MAX + 1] = { -1, -1, };

int main(){
    for(int i = 2; i < MAX + 1; i++){
        arr[i] = i;
    }
    for(int i = 2; i < 7500; i++){
        for(int j = i * i; j < MAX + 1; j += i){
            if(arr[j] == j)
                arr[j] = i;
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cout << arr[a] << " ";
        a /= arr[a];
        while (a > 1){
            cout << arr[a] << " ";
            a /= arr[a];
        }
        cout << "\n";
    }
}
