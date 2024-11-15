#include <iostream>
#include <stack>
using namespace std;
int arr[1001];
stack<int> st;

int main(){
    int n, a;
    cin >> n;
    int cur = 1;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a != cur)
            st.push(a);
        else{
            cur++;
        }
        while(!st.empty()){
            if(st.top() == cur){
                st.pop();
                cur++;
            }
            else
                break;
        }
    }
    if(st.empty()){
        cout << "Nice";
    }
    else
        cout << "Sad";

    return 0;
}