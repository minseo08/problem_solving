#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;
vector<pair<int, int>> vec;
int arr[1001];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int d, w;
        cin >> d >> w;
        vec.push_back(make_pair(d, w));
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < n; i++){
        for(int j = vec[i].first; j > 0; j--){
            if(arr[j] == 0){
                arr[j] = vec[i].second;
                break;
            }
        }
    }
    int res = 0;
    for(int i = 0; i < MAX; i++){
        res += arr[i];
    }
    cout << res;
    return 0;
}