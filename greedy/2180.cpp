#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == 0){
        return false;
    }
    else if(b.first == 0){
        return true;
    }
    else if(a.second == 0 && b.second == 0){
        return a.first < b.first;
    }
    return a.second * b.first < b.second * a.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), compare);
    long long t = 0;
    for(int i = 0; i < n; i++){
        t += t * v[i].first;
        t += v[i].second;
        t %= 40000;
    }
    cout << t;
    return 0;
}