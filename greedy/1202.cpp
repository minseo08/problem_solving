#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, k;
pair<int, int> jew[300001];
int bag[300001];
priority_queue<int, vector<int>, less<int>> pq;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> jew[i].first >> jew[i].second;
    }
    for (int i = 0; i < k; ++i) {
        cin >> bag[i];
    }
    sort(jew, jew + n);
    sort(bag, bag + k);
    int idx = 0;
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && bag[i] >= jew[idx].first) {
            pq.push(jew[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}