#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    set<string> set;
    string str = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            set.insert(str); //중복인 것은 insert안됨
        }
        str = "";
    }
 
    cout << set.size();
}