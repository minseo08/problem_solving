#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    cout << vec[k - 1];
    return 0;
}