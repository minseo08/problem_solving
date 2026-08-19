#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> max_pq;
    for(int i = 0; i < operations.size(); i++){
        if(operations[i][0] == 'I'){
            int tmp = stoi(operations[i].substr(2));
            max_pq.push(tmp);
        }
        else{
            if(max_pq.empty())
                continue;
            if(stoi(operations[i].substr(2)) == 1){//max delete
                max_pq.pop();
            }
            else{//min delete
                priority_queue<int, vector<int>, greater<int>> min_pq;
                while(!max_pq.empty()){
                    min_pq.push(max_pq.top());
                    max_pq.pop();
                }
                min_pq.pop();
                while(!min_pq.empty()){
                    max_pq.push(min_pq.top());
                    min_pq.pop();
                }
            }
        }
    }
    vector<int> answer;
    if(max_pq.empty()){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    int tmp = 0;
    int len = max_pq.size();
    while(!max_pq.empty()){
        if(tmp == 0)
            answer.push_back(max_pq.top());
        if(tmp == len - 1)
            answer.push_back(max_pq.top());
        max_pq.pop();
        tmp++;
    }

    return answer;
}