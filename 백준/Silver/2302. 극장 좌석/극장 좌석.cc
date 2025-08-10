#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int dp[41];

int main(){
    int n, m;
    cin >> n >> m;
    stack<int> st;
    vector<int> seq;
    st.push(0);
    for(int i = 0; i < m; i++){
        int v;
        cin >> v;
        seq.push_back(v - 1 - st.top());
        st.push(v);
    }
    seq.push_back(n - st.top());
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    int res = 1;
    for(int i = 0; i < seq.size(); i++){
        res *= dp[seq[i]];
    }
    cout << res;
    return 0;
}
//k개 연속 좌석에서는 몇 번의 경우의 수?
//맨 앞에 놈 바뀌거나(n - 2) 안바뀌거나(n - 1)