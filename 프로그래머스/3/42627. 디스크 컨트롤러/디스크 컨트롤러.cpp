#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> arr[1001];

class cmp{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            if(a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int len = jobs.size();
    sort(jobs.begin(), jobs.end());
    for(int j = 0; j < jobs.size(); j++){
        arr[jobs[j][0]].push_back(jobs[j][1]);
    }
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int flag = 0;
    int done = 0;
    int i = 0;
    for(int i = 0; i <= flag; i++){
        if(i <= jobs[len - 1][0] && arr[i].size()){
            for(int j = 0; j < arr[i].size(); j++)
                pq.push({i, arr[i][j]});
        }
        if(i == flag){
            if(!pq.empty()){
                flag += pq.top().second;
                answer += flag - pq.top().first;
                done++;
                pq.pop();
            }
            else if(done < len){
                flag++;
            }
        }
        //cout << i << " " << flag << "\n";
    }
    answer /= len;
    //cout << answer;
    return answer;
}