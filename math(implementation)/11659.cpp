#include <iostream>
using namespace std;
int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        sum += a;
        arr[i] += sum;
    }
    for(int i = 0; i < m; i++){
        int b, c;
        cin >> b >> c;
        cout << arr[c] - arr[b - 1] << "\n";
    }
    return 0;
}