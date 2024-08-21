#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n;
	cin >> n;
    int x, a, b;
    int answer = 1;
	for (int i = 0; i < n; i++) {
		cin >> x >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int startTime = v[i].first;
		int endTime = v[i].second;

		if (pq.empty()) {
			pq.push(endTime);
		}
		else {
			if (pq.top() > startTime) {
				answer++;
			}
			else {
				pq.pop();
			}
			pq.push(endTime);
		}
	}
	cout << answer;
}