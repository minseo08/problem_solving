#include <string>
#include <vector>
#include <iostream>
using namespace std;
int tmp;

void dfs(int num, vector<int> g[101], bool visited[101]){
    tmp++;
    visited[num] = true;
    for(int i = 0; i < g[num].size(); i++){
        if(!visited[g[num][i]])
            dfs(g[num][i], g, visited);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for(int del = 0; del < wires.size(); del++){
        vector<int> graph[101];
        bool visited[101] = {0, 0, };
        for(int i = 0; i < wires.size(); i++){
            if(i == del)
                continue;
            graph[wires[i][0]].push_back(wires[i][1]);
            graph[wires[i][1]].push_back(wires[i][0]);
        }
        tmp = 0;
        dfs(1, graph, visited);
        answer = min(answer, abs(n - tmp - tmp));
    }
    return answer;
}