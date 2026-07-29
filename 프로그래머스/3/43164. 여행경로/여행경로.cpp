#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
priority_queue<int, vector<int>, greater<int>> graph[1000001];
map<int, string> mp;
vector<string> answer;

void dfs(int curr){
    while(!graph[curr].empty()){
        int next = graph[curr].top();
        graph[curr].pop();
        dfs(next);
    }
    answer.push_back(mp[curr]);
}

int my_hash(string str){
    string tmp;
    for(int i = 0; i < str.size(); i++){
        if(str[i] - 'A' < 10)
            tmp += '0';
        tmp += to_string(str[i] - 'A');
    }
    mp[stoi(tmp)] = str;
    return stoi(tmp);
}

vector<string> solution(vector<vector<string>> tickets) {
    for(int i = 0; i < tickets.size(); i++){
        graph[my_hash(tickets[i][0])].push(my_hash(tickets[i][1]));
    }
    dfs(my_hash("ICN"));
    reverse(answer.begin(), answer.end());
    return answer;
}