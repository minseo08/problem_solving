#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec_x[10001];
vector<int> vec_y[10001];
int sum = 0;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        vec_x[x].push_back(y);
        vec_y[y].push_back(x);
    }
    for(int i = 0; i < 10001; i++){
        sort(vec_x[i].begin(), vec_x[i].end());
        sort(vec_y[i].begin(), vec_y[i].end());
        for(int j = 1; j < vec_x[i].size(); j += 2)
            sum += vec_x[i][j] - vec_x[i][j - 1];
        for(int j = 1; j < vec_y[i].size(); j += 2)
            sum += vec_y[i][j] - vec_y[i][j - 1];
    }
    cout << sum;
    return 0;
}