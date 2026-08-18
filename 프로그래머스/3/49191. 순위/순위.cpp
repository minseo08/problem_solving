#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> graph_win[101];
vector<int> graph_lose[101];

bool visited[101];
int result[101];
int cnt = 0;

void dfs(int num, vector<int>* graph){
    //cout << num << "\n";
    for(int i = 0; i < graph[num].size(); i++){
        int tmp = graph[num][i];
        //cout << tmp << ":" << visited[tmp] << "\n";
        if(!visited[tmp]){
            visited[tmp] = true;
            cnt++;
            dfs(tmp, graph);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    for(int i = 0; i < results.size(); i++){
        graph_win[results[i][1]].push_back(results[i][0]);
    }
    for(int i = 0; i < results.size(); i++){
        graph_lose[results[i][0]].push_back(results[i][1]);
    }
    for(int i = 1; i <= n; i++){
        dfs(i, graph_win);
        result[i] += cnt;
        cnt = 0;
        for(int j = 0; j <= n; j++)
            visited[j] = false;
    }
    for(int i = 1; i <= n; i++){
        dfs(i, graph_lose);
        result[i] += cnt;
        cnt = 0;
        for(int j = 0; j <= n; j++)
            visited[j] = false;
    }
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(result[i] == n - 1)
            answer++;
    }
    return answer;
}
//visited 매번 초기화가 최선??