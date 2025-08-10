#include <iostream>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
vector<int> graph[101];
int res[101];
queue<int> q;
int n, m;

void init(){
    for(int i = 1; i <= n; i++)
        res[i] = 0;
}

void bfs(int curr){
    q.push(curr);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i = 0; i < graph[tmp].size(); i++){
            int sibal = graph[tmp][i];
            if(!res[sibal]){
                res[sibal] += res[tmp] + 1;
                q.push(sibal);
            }
        }
    }
}



int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = 1;
    int sum_cand = INF;
    for(int i = 1; i <= n; i++){
        bfs(i);
        int sum = 0;
        for(int j = 1; j <= n; j++){
            sum += res[j];
        }
        if(sum < sum_cand){
            ans = i;
            sum_cand = sum;
        }
        init();
    }
    cout << ans;
    return 0;
}

// 1 -> 2+1+1+2
// 2 -> 2+1+2+3
// 3 -> 1+1+1+2
// 4 -> 1+2+1+1
// 5 -> 2+3+2+1