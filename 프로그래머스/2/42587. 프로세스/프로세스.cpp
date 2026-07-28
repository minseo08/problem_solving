#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    int sum = 0;
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    while(!q.empty()){
        if(pq.top() > q.front().first){
            pair<int, int> tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        else{
            sum++;
            if(q.front().second == location)
                return sum;
            q.pop();
            pq.pop();
        }
    }
}