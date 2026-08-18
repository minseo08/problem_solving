#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define MAX 20001
#define INF 987654321

using namespace std;
vector<int> graph[MAX];
bool visited[MAX];

int bfs(int num){
    int answer = 0;
    int max_cnt = 0;
    queue<pair<int, int>> q;
    q.push({num, 0});
    visited[num] = true;
    int cnt = 0;
    while(!q.empty()){
        int tmp = q.front().first;
        int curr_cnt = q.front().second;
        if(curr_cnt > max_cnt){
            max_cnt = curr_cnt;
            answer = 1;
        }
        else if(curr_cnt == max_cnt){
            max_cnt = curr_cnt;
            answer++;
        }
        q.pop();
        for(int i = 0; i < graph[tmp].size(); i++){
            if(!visited[graph[tmp][i]]){
                visited[graph[tmp][i]] = true;
                q.push({graph[tmp][i], curr_cnt + 1});
            }
        }
    }
    return answer;
}

int solution(int n, vector<vector<int>> edge){
    int answer = 0;
    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    return bfs(1);
}

// int solution(int n, vector<vector<int>> edge) {
//     for(int i = 0; i < MAX; i++)
//         arr[i] = INF;
    
//     int answer = 0;
//     for(int i = 0; i < edge.size(); i++){
//         graph[edge[i][0]].push_back(edge[i][1]);
//         graph[edge[i][1]].push_back(edge[i][0]);
//     }
//     arr[0] = 0;
//     arr[1] = 0;
//     for(int i = 0; i < graph[1].size(); i++)
//         arr[graph[1][i]] = 1;
//     for(int i = 2; i <= n; i++){
//         for(int j = 0; j < graph[i].size(); j++){
//             arr[i] = min(arr[graph[i][j]] + 1, arr[i]);
//             arr[graph[i][j]] = min(arr[i] + 1, arr[graph[i][j]]);
//         }
//     }
//     int m = 0;
//     for(int i = 2; i <= n; i++){
//         if(arr[i] > m){
//             m = arr[i];
//             answer = 1;
//         }
//         else if(arr[i] == m){
//             m = arr[i];
//             answer++;
//         }
//     }
//     return answer;
// }