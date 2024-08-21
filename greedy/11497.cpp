#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> v(n);
        
		for (int i = 0; i < n; i++){
            cin >> v[i];
        }
		sort(v.begin(), v.end());
		int res = 0;
		res = max(res, v[1] - v[0]);
		res = max(res, v[n - 1] - v[n - 2]);
        
		for (int i = 0; i < n - 2; i++) {
			res = max(res, v[i + 2] - v[i]);
		}
		cout << res << "\n";
	}
}