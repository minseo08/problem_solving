#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int arr[9];
int res[9];
bool visited[9];
set<vector<int>> ans;
int n, m;

void dfs(int num, int cnt){
    if(cnt == m){
        vector<int> vec;
        for(int i = 0; i < cnt; i++){
            vec.push_back(res[i]);
        }
        ans.insert(vec);
        return;
    }
    for(int i = num; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            res[cnt] = arr[i];
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0, 0);
    set<vector<int>>::iterator it;
    for(it = ans.begin(); it != ans.end(); it++){
        for(int i = 0; i < it->size(); i++){
            cout << *(it->begin() + i) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}