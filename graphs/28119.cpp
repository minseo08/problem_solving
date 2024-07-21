#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int>>> vec;
bool visited[2001];
int parent[2001];
int find_parent(int tmp){
    if(parent[tmp] == tmp){
        return tmp;
    }
        return parent[tmp] = find_parent(parent[tmp]);
}
void uni(int f, int e){
    if(parent[find_parent(e)] == find_parent(f)){
        return;
    }
    parent[find_parent(e)] = find_parent(f);
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back({w, {u, v}});
    }
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    int res = 0;
    int cnt = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        if(parent[find_parent(vec[i].second.second)] == find_parent(vec[i].second.first)){
            continue;
        }
        parent[find_parent(vec[i].second.second)] = find_parent(vec[i].second.first);
        res += vec[i].first;
        cnt++;
        if(cnt == n - 1){
            break;
        }
    }
    cout << res;
    return 0;
}