#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> graph[18];
int answer = 0;

void dfs(int curr, int sheep_cnt, int wolf_cnt, vector<int> &info, vector<int> nodes){
    if(info[curr] == 0)
        sheep_cnt++;
    else
        wolf_cnt++;
    if(sheep_cnt <= wolf_cnt)
        return;
    
    answer = max(sheep_cnt, answer);
    for(int i = 0; i < nodes.size(); i++){
        int tmp = nodes[i];
        vector<int> curr_nodes = nodes;
        curr_nodes.erase(curr_nodes.begin() + i);
        for(int j = 0; j < graph[tmp].size(); j++)
            curr_nodes.push_back(graph[tmp][j]);
        dfs(tmp, sheep_cnt, wolf_cnt, info, curr_nodes);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i = 0; i < edges.size(); i++){
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    dfs(0, 0, 0, info, graph[0]);
    return answer;
}