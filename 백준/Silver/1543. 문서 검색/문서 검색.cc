#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str, finding;
int cnt = 0;

int main(){
    getline(cin, str);
    getline(cin, finding);
    for(int i = 0; i < str.size(); i++){
        if (finding == str.substr(i, finding.size())){
            cnt++;
            i += finding.size() - 1;
        }
    }
    cout << cnt;
    return 0;
}