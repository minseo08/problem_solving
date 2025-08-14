#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        map<string, int> mp;
        int cloth, res = 1;
        cin >> cloth;
        for(int j = 0; j < cloth; j++){
            string a, b;
            cin >> a >> b;
            mp[b]++;
        }
        map<string, int>::iterator it;
        for(it = mp.begin(); it != mp.end(); it++){
            res *= (it->second + 1);
        }
        cout << res - 1 << "\n";
    }
    return 0;
}