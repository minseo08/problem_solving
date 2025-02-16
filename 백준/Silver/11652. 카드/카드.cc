#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<long long, int> m;

bool cmp(pair<long long, int> p1, pair<long long, int> p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        m[num]++;
    }
    vector<pair<long long, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    cout << vec[0].first;
    return 0;
}