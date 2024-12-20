#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    bool res = false;
    while(1){
        res = true;
        stack<int> s;
        string str;
        getline(cin, str);
        if(str == ".")
            break;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '[' || str[i] == '(')
                s.push(str[i]);
            else if(str[i] == ']'){
                if(s.empty()){
                    res = false;
                    break;
                }
                else if(s.top() == '[')
                    s.pop();
                else if(s.top() == '('){
                    res = false;
                    break;
                }
            }
            else if(str[i] == ')'){
                if(s.empty()){
                    res = false;
                    break;
                }
                else if(s.top() == '(')
                    s.pop();
                else if(s.top() == '['){
                    res = false;
                    break;
                }
            }
        }
        if(s.empty() && res)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}