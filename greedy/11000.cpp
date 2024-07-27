#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    int n, a, b;
    cin >> n;
    for(int i = n; i > 0; i--){
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        pq.push(vec[i].second);
        if(pq.top() <= vec[i].first){
            pq.pop();
        }
    }
    cout << pq.size();
    return 0;
}