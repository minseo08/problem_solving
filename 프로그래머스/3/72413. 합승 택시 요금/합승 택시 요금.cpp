#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[201]; // weight, node
int arr[201];
int t[201];

void dijk(int n, int s){
    for(int i = 1; i <= n; i++)
        arr[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight, node
    pq.push({0, s});
    arr[s] = 0;
    while(!pq.empty()){
        pair<int, int> tmp = pq.top();
        int curr_weight = tmp.first;
        int curr_node = tmp.second;
        pq.pop();
        for(int i = 0; i < graph[curr_node].size(); i++){
            int next_node = graph[curr_node][i].second;
            int next_weight = graph[curr_node][i].first;
            if(arr[next_node] > arr[curr_node] + next_weight){
                arr[next_node] = arr[curr_node] + next_weight;
                pq.push({arr[next_node], next_node});
            }
            
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i = 0; i < fares.size(); i++){
        graph[fares[i][0]].push_back({fares[i][2], fares[i][1]});
        graph[fares[i][1]].push_back({fares[i][2], fares[i][0]});
    }
    vector<int> result1;
    vector<int> result2;
    vector<int> result3;
    
    int answer = INF;
    dijk(n, s);
    for(int i = 0; i <= n; i++)
        result1.push_back(arr[i]);
    dijk(n, a);
    for(int i = 0; i <= n; i++)
        result2.push_back(arr[i]);
    dijk(n, b);
    for(int i = 0; i <= n; i++)
        result3.push_back(arr[i]);
    
    for(int i = 1; i <= n; i++){
        if(result1[a] != INF && result1[b] != INF)
            answer = min(answer, result1[a] + result1[b]);
        if(result1[i] != INF && result2[i] != INF && result3[i] != INF)
            answer = min(answer, result1[i] + result2[i] + result3[i]);
    }

    return answer;
}