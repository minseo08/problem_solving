#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;

int main(){
    int n, c, res = 0;
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int start = 1;
    int end =  vec[n - 1] - vec[0];
    int mid, r;
    while(start <= end){
        r = 1;
        mid = (end + start) / 2;
        int s = vec[0];
        for(int i = 1; i < n; i++){
            if(vec[i] - s >= mid){
                r++;
                s = vec[i];
            }
        }
        if(r >= c){
            start = mid + 1;
            res = max(res, mid);
        }
        else{
            end = mid - 1;
        }
    }
    cout << res;
    return 0;
}