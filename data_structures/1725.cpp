#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

stack<pair<int, long long>> s;
long long res;
int main(){
    int n, idx = 0;
    cin >> n;
    for(int i = 0; i <= n; i++){
        long long h;
        if(i < n){
            cin >> h;
        }
        else{
            h = 0;
        }
        idx = i;
        while(!s.empty() && s.top().second >= h){
            idx = s.top().first;
            res = max(res, s.top().second * (i - idx));
            s.pop();
        }
        s.push({idx, h});
    }
    cout << res;
    return 0;
}