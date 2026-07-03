#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> st;
    st.push(-1);
    for(int i = arr.size() - 1; i >= 0; i--){
        if(st.top() != arr[i])
            st.push(arr[i]);
    }
    vector<int> answer;
    while(st.top() != -1){
        answer.push_back(st.top());
        st.pop();
    }

    return answer;
}