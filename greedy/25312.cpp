#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second / (double)a.first > b.second / (double)b.first;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<pair<int, int>> juice(n);
    for (int i = 0; i < n; i++) {
        cin >> juice[i].first >> juice[i].second;
    }
    
    sort(juice.begin(), juice.end(), compare);
    
    long long a = 0, b = 1;
    long long M = 0;
    int idx = 0;
    
    while (M + juice[idx].first < m) {
        M += juice[idx].first;
        a += juice[idx].second;
        idx++;
    }
    
    b = juice[idx].first;
    a *= b;
    a += juice[idx].second * (m - M);

    long long commonDivisor = gcd(a, b);
    cout << a / commonDivisor << "/" << b / commonDivisor << endl;

    return 0;
}
