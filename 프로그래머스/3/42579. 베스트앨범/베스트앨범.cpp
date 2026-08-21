#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class cmp{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>> mp;
    map<string, int> total;
    bool visited[100001];
    for(int i = 0; i < genres.size(); i++){
        mp[genres[i]].push({plays[i], i});
        total[genres[i]] += plays[i];
    }
    priority_queue<pair<int, string>> pq;
    map<string, int>::iterator it;
    for(it = total.begin(); it != total.end(); it++){
        pq.push({it->second, it->first});
    }
    
    vector<int> answer;
    while(!pq.empty()){
        string tmp = pq.top().second;
        int cnt = 0;
        int len = mp[tmp].size();
        while(cnt < len && !mp[tmp].empty() && cnt < 2){
            answer.push_back(mp[tmp].top().second);
            mp[tmp].pop();
            cnt++;
        }
        pq.pop();
    }
    
    return answer;
}