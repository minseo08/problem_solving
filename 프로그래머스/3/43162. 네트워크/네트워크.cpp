#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> graph[201];
bool visited[201];

void dfs(int num){
    visited[num] = true;
    //cout << num << " ";
    for(int i = 0; i < graph[num].size(); i++){
        int tmp = graph[num][i];
        if(!visited[tmp])
            dfs(tmp);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            if(computers[i][j] && i != j)
                graph[i].push_back(j);
        }
    }
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        if(!visited[i]){
            answer++;
            dfs(i);
            //cout << "\n";
        }
    }
    return answer;
}