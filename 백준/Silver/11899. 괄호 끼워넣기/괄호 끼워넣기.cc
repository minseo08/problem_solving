#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
stack<int> st;

int main(){
    int cnt = 0;
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ')'){
            if(st.empty())
                cnt++;
            else
                st.pop();
        }
        else{
            st.push(str[i]);
        }
    }
    cout << cnt + st.size();
    return 0;
}