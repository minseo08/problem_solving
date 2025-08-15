#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++){
        if((100 - progresses[i]) % speeds[i]){
            q.push((100 - progresses[i]) / speeds[i] + 1);
        }
        else{
            q.push((100 - progresses[i]) / speeds[i]);
        }
    }
    int tmp = q.front();
    int cnt = 1;
    q.pop();
    vector<int> answer;
    while(!q.empty()){
        if(tmp < q.front()){
            tmp = q.front();
            answer.push_back(cnt);
            cnt = 1;
        }
        else{
            cnt++;
        }
        q.pop();
    }
    answer.push_back(cnt);
    return answer;
}