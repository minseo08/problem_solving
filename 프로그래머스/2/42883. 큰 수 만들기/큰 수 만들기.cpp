#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

string solution(string number, int k) {
    deque<char> dq;
    dq.push_back(number[0]);
    for(int i = 1; i < number.size(); i++){
        if(k == 0){
            dq.push_back(number[i]);
            continue;
        }
        while(!dq.empty() && dq.back() < number[i] && k > 0){
            dq.pop_back();
            k--;
        }
        dq.push_back(number[i]);
    }
    string answer = "";
    while(k > 0){
        dq.pop_back();
        k--;
    }
    while(!dq.empty()){
        answer += dq.front();
        dq.pop_front();
    }
    return answer;

}