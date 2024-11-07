#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
map<string, bool> mp;
vector<string> vec;
int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        mp[str] = true;
    }
    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        if(mp[str] == true){
            mp[str] = false;
            cnt++;
        }
        else{
            mp[str] = true;
        }
    }
    cout << cnt << "\n";
    map<string, bool>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        if(!it->second)
            cout << it->first << "\n";
    }
    return 0;
}