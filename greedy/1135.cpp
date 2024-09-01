#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> tree[55];

int solve(int node) {
	if (tree[node].empty()) {
		return 1;
	}
	vector<int> child;
	for (int i = 0; i < tree[node].size(); i++) {
		child.push_back(solve(tree[node][i]) + 1);
	}
	sort(child.begin(), child.end(), greater<int>());
	int ret = 0;
	for (int i = 0; i < child.size(); i++) {
		ret = max(ret, child[i] + i);
	}
	return ret;
}

int main() {
    int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (i == 0) continue; 
		tree[vec[i]].push_back(i);
	}
	cout << solve(0) - 1 << "\n";
}