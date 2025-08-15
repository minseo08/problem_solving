#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    int answer = 0;
    
    while(pq.top() < K){
        if(pq.size() < 2){
            return -1;
        }
        answer++;
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp + (pq.top() * 2));
        pq.pop();
    }
    
    return answer;
}