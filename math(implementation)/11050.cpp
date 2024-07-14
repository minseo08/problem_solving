#include <iostream>
using namespace std;
int arr[9];
bool visited[9];
int n, m, cnt = 0;
void bfs(int num, int depth){
    if (depth == m){
        //for(int i = 0; i < m; i++){
        //   cout << arr[i] << " ";
        //}
        //cout << "\n";
        cnt++;
        return;
    }
    for(int i = num; i <= n; i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[depth] = i;
            bfs(i, depth + 1);
            visited[i] = false;
        }
    }
}


int main(){
    cin >> n >> m;
    bfs(1, 0);
    cout << cnt;
    return 0;
}