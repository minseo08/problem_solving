#include <iostream>
#include <stack>
using namespace std;
int arr[1000000];
int ans[1000000];
stack<int> s;
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && arr[i] >= s.top()){
            s.pop();
        }
        if(s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(arr[i]);
    }
    for(int i = 0 ; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}