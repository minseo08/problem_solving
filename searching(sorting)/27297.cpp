#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> vec[1001];
vector<long long> res;

int main(){
    int n, m;
    long long sum = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            long long x;
            cin >> x;
            vec[j].push_back(x);
        }
    }
    for(int i = 0; i < n; i++){
        sort(vec[i].begin(), vec[i].end());
        res.push_back(vec[i][m / 2]);
        for(int j = 0; j < m; j++){
            sum += abs(vec[i][j] - vec[i][m / 2]);
        }
    }
    cout << sum << "\n";
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    return 0;
}


