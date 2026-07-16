#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> graph[51];
bool visited[51];
int answer = 0;

bool comp(string a, string b){
    int len = a.size();
    int sum = 0;
    for(int i = 0; i < len; i++){
        if(a[i] == b[i])
            sum++;
    }
    if(sum == len - 1)
        return true;
    else
        return false;
}

void bfs(int tmp, string target, vector<string> words){
    queue<pair<int, int>> q;
    q.push({tmp, 0});
    while(!q.empty()){
        int num = q.front().first;
        int mv = q.front().second;
        visited[num] = true;
        q.pop();
        //cout << num << " " << mv << "\n";
        if(words[num] == target){
            answer = mv;
            return;
        }
        for(int i = 0; i < graph[num].size(); i++){
            if(!visited[graph[num][i]])
                q.push({graph[num][i], mv + 1});
        }
    }
    answer = 0;
    return;
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    for(int i = 0; i < words.size(); i++){
        for(int j = i + 1; j < words.size(); j++){
            if(comp(words[i], words[j])){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    visited[words.size() - 1] = true;
    bfs(words.size() - 1, target, words);
    return answer;
}