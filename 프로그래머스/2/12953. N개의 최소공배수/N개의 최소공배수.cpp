#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int lcm(int a, int b){
    int mul = a * b;
    if(b > a){
        int tmp = a;
        a = b;
        b = tmp;
    }
    while(a % b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    //gcd = b;
    return mul / b;
}

int solution(vector<int> arr) {
    stack<int> st;
    for(int i = 0; i < arr.size(); i++)
        st.push(arr[i]);
    while(st.size() > 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(lcm(a, b));
    }
    int answer = st.top();
    return answer;
}