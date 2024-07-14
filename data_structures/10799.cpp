#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    string str;
    cin >> str;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(')
            s.push(str[i]);
        else if(str[i] == ')'){
            if(str[i - 1] == '('){
                s.pop();
                cnt += s.size();
            }
            else{
                s.pop();
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}