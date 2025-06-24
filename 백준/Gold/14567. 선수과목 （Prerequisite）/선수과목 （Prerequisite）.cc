#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> pre[1001];
int income[1001];
int arr[1001];
queue<int> q;

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        pre[a].push_back(b);
        income[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(!income[i])
            q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < pre[x].size(); i++){
            int y = pre[x][i];
            income[y]--;
            if(income[y] == 0){
                q.push(y);
                arr[y] = max(arr[y], arr[x] + 1);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] + 1 << " ";
    }
    return 0;
}