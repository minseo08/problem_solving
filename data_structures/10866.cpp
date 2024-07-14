#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push_front"){
            int a;
            cin >> a;
            dq.push_front(a);
        }
        if(cmd == "push_back"){
            int a;
            cin >> a;
            dq.push_back(a);
        }
        else if(cmd == "pop_front"){
            if(dq.empty())
                cout << "-1" << "\n";
            else{
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(dq.empty())
                cout << "-1" << "\n";
            else{
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if(cmd == "size"){
            cout << dq.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << dq.empty() << "\n";
        }
        else if(cmd == "front"){
            if(dq.empty())
                cout << "-1" << "\n";
            else
                cout << dq.front() << "\n";
        }
        else if(cmd == "back"){
            if(dq.empty())
                cout << "-1" << "\n";
            else
                cout << dq.back() << "\n";
        }
        
    }
    return 0;
}