#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1025][1025];

int pooling(int sx, int sy, int sn){
    if(sn > 2){
        vector<int> res;
        int nn = sn / 2;
        res.push_back(pooling(sx, sy, nn));
        res.push_back(pooling(sx, sy + nn, nn));
        res.push_back(pooling(sx + nn, sy, nn));
        res.push_back(pooling(sx + nn, sy + nn, nn));
        sort(res.begin(), res.end());
        return res[2];
    }
    vector<int> vec;
    for(int i = sx; i < sx + 2; i++){
        for(int j = sy; j < sy + 2; j++){
            vec.push_back(arr[i][j]);
        }
    }
    sort(vec.begin(), vec.end());
    return vec[2];
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    cout << pooling(0, 0, n);
    return 0;
}