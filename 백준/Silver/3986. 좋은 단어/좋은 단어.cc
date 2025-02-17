#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        stack<char> s;
        for(int j = 0; j < str.size(); j++){
            char tmp = str[j];
            if(s.empty()){
                s.push(tmp);
            }
            else{
                if(s.top() == tmp){
                    s.pop();
                }
                else
                    s.push(tmp);
            }
        }
        if(s.empty())
            cnt++;
    }
    cout << cnt;
    return 0;
}