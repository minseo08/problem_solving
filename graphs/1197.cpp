#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int>>> vec;
int parent[10001];
int find_parent(int a){
    if(parent[a] == a){
        return a;
    }
    else{
        return parent[a] = find_parent(parent[a]);
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({c, {a, b}});
    }
    sort(vec.begin(), vec.end());
    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < vec.size(); i++){
        //v[i].second.first
        //v[i].second.second
        if(find_parent(vec[i].second.first) == find_parent(vec[i].second.second)){
            continue;
        }
        parent[find_parent(vec[i].second.second)] = find_parent(vec[i].second.first);
        res += vec[i].first;
        if(++cnt == v - 1){
            break;
        }
    }
    cout << res;
    return 0;
}