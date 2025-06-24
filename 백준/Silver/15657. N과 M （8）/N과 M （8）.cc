#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
int res[9];
int n, m;

void dfs(int start, int cnt){
    if(cnt == m){
        for(int j = 0; j < m; j++){
            cout << arr[res[j]] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = start; i < n; i++){
        res[cnt] = i;
        dfs(i, cnt + 1);
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0, 0);
    return 0;
}