
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    string result;
    int temp = 1;
    bool is_no = false;
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        while(temp <= a){
            result += '+';
            s.push(temp);
            temp++;
        }
        if(s.top() == a){
            s.pop();
            result += '-';
        }
        else{
            is_no = true;
            continue;
        }
    }
    if(is_no)
        cout << "NO";
    else{
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << "\n";
    }
    return 0;
}