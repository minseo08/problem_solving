#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, string> mymap;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        mymap.insert({str1, str2});
    }
    for(int i = 0; i < m; i++){
        string inp;
        cin >> inp;
        cout << mymap[inp] << "\n";
    }
    return 0;
}