#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
bool visited[9];
int res[9];
int n, m;

void dfs(int start, int depth){
    if(depth == m){
        for(int i = 0; i < m; i++)
            cout << arr[res[i]] << " ";
        cout << "\n";
    }
    for(int i = start; i < n; i++){
        if(!visited[i]){
            res[depth] = i;
            visited[i] = true;
            dfs(i + 1, depth + 1);
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
    dfs(0, 0);
    return 0;
}