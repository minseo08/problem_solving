#include <iostream>
#include <stack>
using namespace std;
stack<int> st;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 0){
            st.pop();
        }
        else
            st.push(a);
    }
    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}