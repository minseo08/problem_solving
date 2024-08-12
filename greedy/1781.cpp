#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF = 98754321;
vector<pair<int, int>> vec;
int n;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
		vec[i].first--;
	}
	sort(vec.begin(), vec.end(),cmp);
	long long sum = 0;
	priority_queue<int> pq;
    int j = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (j < n && i == vec[j].first) {
			pq.push(vec[j].second);
			j++;
		}
	
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	
	}
	cout << sum;
	return 0;
}

