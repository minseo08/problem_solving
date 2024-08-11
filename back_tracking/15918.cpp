#include <iostream>
using namespace std;

int n;
int ans = 0;
bool visited[13];
int arr[25];

void func(int idx) {
	if (idx > n) {
		ans++;
		return;
	}
	if (visited[idx]){
        func(idx + 1);
    }
	else {
		int r = 2 * n - idx - 1;
		for (int i = 1; i <= r; i++) {
			int temp = i + idx + 1;
			if (!arr[i] && !arr[temp]) {
				arr[i] = arr[temp] = idx;
				func(idx + 1);
				arr[i] = arr[temp] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
    cin >> n >> x >> y;
	arr[x] = y - x - 1;
    arr[y] = y - x - 1;
	visited[y - x - 1] = true;
	func(1);
	cout << ans;
}