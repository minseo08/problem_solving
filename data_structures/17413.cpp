#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> s;
    string str;
    getline(cin, str);
    str += ' ';
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ' || str[i] == '<'){
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            if(str[i] == ' ')
                cout << " ";
            
            if(str[i] == '<'){
                while(str[i] != '>'){
                    cout << str[i];
                    i++;
                }
            cout << str[i];
            }
        }
        else if(str[i] != ' ')
            s.push(str[i]);
    }
    
    return 0;
}