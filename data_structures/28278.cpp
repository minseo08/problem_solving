#include <iostream>
#include <stack>
using namespace std;
stack<int> st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 1){
            int x;
            cin >> x;
            st.push(x);
        }
        else if(a == 2){
            if(st.empty())
                cout << "-1" << "\n";
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(a == 3){
            cout << st.size() << "\n";
        }
        else if(a == 4){
            if(st.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        }
        else if(a == 5){
            if(st.empty())
                cout << "-1" << "\n";
            else{
                cout << st.top() << "\n";
            }
        }
    }
    return 0;
}
