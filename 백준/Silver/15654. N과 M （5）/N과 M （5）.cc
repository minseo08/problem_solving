#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int res[10];
bool visited[10];
int n, m;

void perm(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++)
            cout << arr[res[i]] << " ";
        cout << "\n";
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            res[cnt] = i;
            perm(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    perm(0);
    return 0;
}