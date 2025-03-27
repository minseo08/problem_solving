#include<iostream>
#include<vector>
using namespace std;
int fibo[46];

int main() {
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i = 2; i < 46; i++){
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int number;
		cin >> number;
		vector<int> answer;
		for(int i = 45; i > 0; i--){
			if(fibo[i] <= number) {
				number -= fibo[i];
				answer.push_back(fibo[i]);
			}
		}
		for(int i = answer.size() - 1; i >= 0; i--){
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
}