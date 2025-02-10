#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;

int main(){
    int cnt, res;
    cin >> cnt;
    int y;
    while(cin >> y){
        vec.push_back(y);
    }
    int s = vec.size();
    sort(vec.begin(), vec.end());
    if(s == 1){
        res = vec[0] * vec[0];
    }
    else{
        res = vec[0] * vec[s - 1];
    }
    cout << res;
    return 0;
}