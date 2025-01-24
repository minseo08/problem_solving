#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> arr;

int main(){
    int cnt = 0;
	cin >> n >> k;
    arr.push_back(0);
    arr.push_back(0);
	for (int i = 2; i <= n; i++){
        arr.push_back(i);
	}

	for (int i = 2; i <= n; i++){
		for (int j = i; j <= n; j += i){
			if (arr[j] != 0){
				arr[j] = 0;
				cnt++;
				if (cnt == k){
					cout << j << "\n";
					return 0;
				}
			}
		}
	}
	return 0;
}