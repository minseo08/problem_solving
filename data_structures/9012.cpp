#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        stack<char> s;
        bool vps = true;
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            if(str[j] == '(')
                s.push(str[j]);
            else if(!s.empty())
                s.pop();
            else
                vps = false;
        }
        if(!s.empty() || !vps)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}