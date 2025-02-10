#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;

int main(){
    int n, y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> y;
        vec.push_back(y);
    }
    sort(vec.begin(), vec.end());
    int res = vec[0] * vec[n - 1];
    cout << res;
    return 0;
}