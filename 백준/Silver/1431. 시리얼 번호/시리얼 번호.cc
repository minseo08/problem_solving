#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int cmp(string a, string b) {
	int asize = a.size();
	int bsize = b.size();
	int asum = 0;
	int bsum = 0;

	if (asize != bsize) {
		return asize < bsize;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			asum += int(a[i]) - 48;
		}

		if (b[i] >= '0' && b[i] <= '9') {
			bsum += int(b[i]) - 48;
		}
	}

	if (asum != bsum) {
		return asum < bsum;
	}
	return a < b;

}

int main() {
	int N;
	string str[50];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	sort(str, str + N, cmp);
	for (int i = 0; i < N; i++) {
		cout << str[i] << "\n";
	}
	
	return 0;
}