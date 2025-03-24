#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string str;
stack<int> s_1;
vector<pair<int, int>> vec;
bool rem[100001];
vector<string> ans;

void dfs(int s, int cnt){
    if(cnt >= 1){
        string tmp = "";
        for(int i = 0; i < str.size(); i++){
            if(!rem[i]){
                tmp += str[i];
            }
        }
        ans.push_back(tmp);
    }
    for(int i = s; i < vec.size(); i++){
        rem[vec[i].first] = true;
        rem[vec[i].second] = true;
        dfs(i + 1, cnt + 1);
        rem[vec[i].first] = false;
        rem[vec[i].second] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            s_1.push(i);
        }
        else if(str[i] == ')'){
            vec.push_back({i, s_1.top()});
            s_1.pop();
        }
    }
    dfs(0, 0);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == ans[i + 1])
            continue;
        cout << ans[i] << "\n";
    }
    return 0;
}