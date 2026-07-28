#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<pair<int, int>> graph[101];
bool visited[101];

int solution(int n, vector<vector<int>> costs) {
    for(int i = 0; i < costs.size(); i++){
        graph[costs[i][0]].push_back({costs[i][2], costs[i][1]});
        graph[costs[i][1]].push_back({costs[i][2], costs[i][0]});
    }
    int cnt = 0;
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        pair<int, int> tmp = pq.top();
        cout << tmp.first << " " << tmp.second << "\n";
        if(visited[tmp.second]){
            pq.pop();
            continue;
        }
        visited[tmp.second] = true;
        cout << "visited!" << tmp.second << "\n";
        pq.pop();
        cnt++;
        answer += tmp.first;
        if(cnt == n)
            break;
        for(int i = 0; i < graph[tmp.second].size(); i++){
            if(!visited[graph[tmp.second][i].second]){
                visited[tmp.second] = true;
                cout << "push:" << graph[tmp.second][i].first << " " << graph[tmp.second][i].second << "\n";
                pq.push(graph[tmp.second][i]);
            }
        }
    }
    return answer;
}