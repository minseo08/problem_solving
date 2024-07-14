#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    int n;
    cin >> str;
    stack<char> left;
    stack<char> right;
    for(int i = 0; i < str.length(); i++){
        left.push(str[i]);
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        if(a == 'L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        else if(a == 'D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        else if(a == 'B'){
            if(!left.empty())
                left.pop();
        }
        else if(a == 'P'){
            char b;
            cin >> b;
            left.push(b);
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }
    return 0;
}