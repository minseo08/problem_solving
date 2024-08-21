#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> pos;
vector<int> neg;
bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a < 0){
            neg.push_back(a);
        }
        else{
            pos.push_back(a);
        }
    }
    sort(pos.begin(), pos.end(), cmp);
    sort(neg.begin(), neg.end());
    
    int sum = 0;
    
    if (!pos.empty() && !neg.empty()) {
        if (pos[0] < abs(neg[0])) {
            sum += abs(neg[0]);
            for (int i = m; i < neg.size(); i += m) {
                sum += abs(neg[i]) * 2;
            }
            for (int i = 0; i < pos.size(); i += m) {
                sum += pos[i] * 2;
            }
        } else {
            sum += pos[0];
            for (int i = m; i < pos.size(); i += m) {
                sum += pos[i] * 2;
            }
            for (int i = 0; i < neg.size(); i += m) {
                sum += abs(neg[i]) * 2;
            }
        }
    }
    else {
        if (!pos.empty()) {
            sum += pos[0];
            for (int i = m; i < pos.size(); i += m) {
                sum += pos[i] * 2;
            }
        }
        if (!neg.empty()) {
            sum += abs(neg[0]);
            for (int i = m; i < neg.size(); i += m) {
                sum += abs(neg[i]) * 2;
            }
        }
    }
    
    cout << sum;
    return 0;

}