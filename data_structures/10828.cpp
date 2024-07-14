#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int n;
    int number;
    string command;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "push"){
            cin >> number;
            s.push(number);
        }
        else if(command == "pop"){
            if(s.size() == 0)
                cout << "-1" << endl;
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if(command == "size")
            cout << s.size() << endl;
        else if(command == "empty"){
            if(s.size() == 0)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else if(command == "top"){
            if(s.size() == 0)
                cout << "-1" << endl;
            else{
                cout << s.top() << endl;
            }
        }
    }
    return 0;
}