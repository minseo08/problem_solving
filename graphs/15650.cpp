#include <iostream>
using namespace std;

int arr[9];
bool visited[9];
int n, m;

void dfs(int num, int depth){
    if(depth == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    for(int i = num; i <= n; i++){
        if(visited[i] == false){
            visited[i] = true;
            arr[depth] = i;
            dfs(i + 1, depth + 1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(1, 0);
}