#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int arr[1001];
bool visited[1001];
int res[1001];
int n, cnt;

void bfs(int num){
    cnt = 1;
    visited[num] = true;
    queue<int> q;
    q.push(arr[num]);
    while(!q.empty()){
        cnt++;
        int tmp = q.front();
        visited[tmp] = true;
        q.pop();
        if(!visited[arr[tmp]]){
            q.push(arr[tmp]);
            visited[arr[tmp]] = true;
        }
    }
}

int main(){
    int max_cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    int res = 1;
    for(int i = 1; i <= n; i++){
        bfs(i);
        if(cnt > max_cnt){
            max_cnt = cnt;
            res = i;
        }
        fill_n(visited, n + 1, false);
    }
    cout << res;
    return 0;
}