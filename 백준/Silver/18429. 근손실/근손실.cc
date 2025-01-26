#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
bool visited[10];
int n, k, tmp, res;

void dfs(int tmp, int cnt){
    if(tmp < 0)
        return;
    if(cnt == n){
        res++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(tmp + arr[i] - k, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //for(int i = 0; i < n; i++){
        //visited[i] = true;
        dfs(tmp, 1);
        //visited[i] = false;
        //tmp = 0;
    //
    cout << res;
    return 0;
}
