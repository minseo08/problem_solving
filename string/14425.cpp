#include <iostream>
#include <map>
using namespace std;
map<string, bool> m;

int main(){
    string str;
    int a, b;
    int res = 0;
	cin >> a >> b;
	for (int i = 0; i < a; i++){
		cin >> str;
		m.insert(pair<string, bool>(str, true));
	}

	for (int i = 0; i < b; i++){
		cin >> str;
		if (m[str] == true){
            res++;
        }
	}
	cout << res;
}