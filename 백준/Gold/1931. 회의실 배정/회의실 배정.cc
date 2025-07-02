#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, res = 1;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    int tmp = v[0].first;
    for(int i = 1; i < n; i++){
        if(tmp <= v[i].second){
            res++;
            tmp = v[i].first;
        }
    }
    cout << res;
    return 0;
}