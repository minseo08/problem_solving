#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<double, int> a, pair<double, int> b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<double, int>> v;
    for(int i = 0; i < n; i++){
        int t, s;
        cin >> t >> s;
        v.push_back({(double)s / t, i + 1});
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < n; i++){
        cout << v[i].second << " ";
    }
    
    return 0;
}