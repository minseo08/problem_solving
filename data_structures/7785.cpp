#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, string, greater<string>> mp;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        mp[str1] = str2;
    }
    map<string, string>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        if(it->second == "enter"){
            cout << it->first << "\n";
        }
    }
    return 0;
}