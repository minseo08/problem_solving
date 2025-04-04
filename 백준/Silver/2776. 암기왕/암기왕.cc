#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t, n, m;
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			mp[num] = 1;
		}
		cin >> m;
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			if (mp[num] == 1)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
}