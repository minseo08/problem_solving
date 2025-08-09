#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, curr, dest, up, down;
queue<int> q;
int cnt[1000001];

void bfs(){
    q.push(curr);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        if(c == dest){
            break;
        }
        int np = c + up;
        int nd = c - down;
        if(np > 0 && np <= n && up && !cnt[np]){
            q.push(np);
            cnt[np] = cnt[c] + 1;
        }
        if(nd > 0 && nd <= n && down && !cnt[nd]){
            q.push(nd);
            cnt[nd] = cnt[c] + 1;
        }
    }
    return;
}

int main(){
    cin >> n >> curr >> dest >> up >> down;
    bfs();
    if(cnt[dest])
        cout << cnt[dest];
    else{
        if(curr == dest)
            cout << 0;
        else
            cout << "use the stairs\n";
    }
    return 0;
}