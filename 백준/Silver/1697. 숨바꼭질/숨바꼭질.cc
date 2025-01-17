#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visited[100001];
int res[100001];
int dx[2] = {1, -1};
queue<int> q;

void bfs(int s, int d){
    q.push(s);
    while(!q.empty()){
        int tmp = q.front();
        if(tmp == d){
            break;
        }
        visited[tmp] = true;
        q.pop();
        int nx;
        for(int i = 0; i < 3; i++){
            if(i == 2)
                nx = 2 * tmp;
            else{
                nx = tmp + dx[i];
            }
            if(nx >= 0 && nx <= 100000 && !visited[nx]){
                if(res[nx] == 0)
                    res[nx] = res[tmp] + 1;
                else{
                    res[nx] = min(res[nx], res[tmp] + 1);
                }
                q.push(nx);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    bfs(n, k);
    cout << res[k];
    return 0;
}