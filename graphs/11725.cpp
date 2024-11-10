#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[100001];
bool visited[100001];
int arr[100001];

void dfs(int cur){
    visited[cur] = true;
    for(int i = 0; i < graph[cur].size(); i++){
        int tmp = graph[cur][i];
        if(!visited[tmp]){
            arr[tmp] = cur;
            dfs(tmp);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for(int i = 2; i <= n; i++)
        cout << arr[i] << "\n";
    return 0;
}