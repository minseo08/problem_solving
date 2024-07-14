#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> mp;
vector<string> v;

bool compare(string a, string b){
    if(mp[a] == mp[b]){
        if(a.size() == b.size()){
            return a < b;
        }
        return a.size() > b.size();
    }
    return mp[a] > mp[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        if(str.size() >= m){
            if(mp.find(str) == mp.end()){
                mp[str] = 0;
                v.push_back(str);
            }
            mp[str]++;
        }
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    return 0;
}