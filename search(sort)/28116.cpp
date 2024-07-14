#include <iostream>
using namespace std;
int arr[500001];
int cnt[500001];
int idx[500001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        idx[arr[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cnt[i] += idx[i] - i;
        cnt[arr[i]] += idx[i] - i;
        int tmp = arr[i];
        arr[i] = arr[idx[i]];
        arr[idx[i]] = tmp;
        idx[tmp] = idx[i];
        idx[i] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << cnt[i] << " ";
    }
    return 0;
}
