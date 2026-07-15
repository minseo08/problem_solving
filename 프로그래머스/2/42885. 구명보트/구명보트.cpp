#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    stack<int> st;
    for(int i = 0; i < people.size(); i++){
        st.push(people[i]);
    }
    int tmp = 0;
    int i = 0;
    while(i < people.size() && tmp < people.size()){
        if(limit - people[i] >= st.top()){
            answer++;
            st.pop();
            tmp += 2;
        }
        else{
            answer++;
            tmp++;
        }
        i++;
    }
    return answer;
}