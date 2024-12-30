#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>
using namespace std;
map<string, int> mp;
vector<string> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        vec.push_back(str);
        mp[str] = i;
        
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(s[0] >= 65 && s[0] <= 90){
            map<string, int>::iterator it;
            it = mp.find(s);
            cout << it->second + 1 << "\n";
        }
        else{
            cout << vec[stoi(s) - 1] << "\n";
        }
    }
    return 0;
}