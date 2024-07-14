#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string str;
        getline(cin, str);
        str += ' ';
        for(int i = 0; i < str.size(); i++){
            if(str[i] != ' ')
                s.push(str[i]);
            else{
                while(s.size() != 0){
                    cout << s.top();
                    s.pop();
                }
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}