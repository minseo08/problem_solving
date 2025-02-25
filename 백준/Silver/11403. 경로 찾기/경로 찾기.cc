#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q;
vector<int> graph[101];
int res[101][101];
bool visited[101];

void bfs(int s){
    q.push(s);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i = 0; i < graph[tmp].size(); i++){
            int dest = graph[tmp][i];
            if(!visited[dest]){
                visited[dest] = true;
                res[s][dest] = 1;
                q.push(dest);
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int num;
            cin >> num;
            if(num)
                graph[i].push_back(j);
        }
    }
    for(int i = 1; i <= n; i++){
        bfs(i);
        for(int i = 1; i <= n; i++){
            visited[i] = false;
        }
    }
    for(int i = 1; i <= n; i++){   
        for(int j = 1; j <= n; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}