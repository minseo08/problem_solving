#include <iostream>
#include <string>
#include <map>
using namespace std;
string str;
map<string, int> m;
int res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str == "ENTER"){
            m.clear();
            continue;
        }
        if(!m[str]){
            res++;
        }
        m[str]++;
    }
    cout << res;
    return 0;
}