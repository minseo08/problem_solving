#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, bool> m;
int cnt = 0;

int main(){
    int n;
    string str1, str2;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str1 >> str2;
        if(str1 == "ChongChong"){
            m[str1] = true;
            m[str2] = true;
        }
        else if(str2 == "ChongChong"){
            m[str1] = true;
            m[str2] = true;
        }
        else if(m[str1]){
            m[str2] = true;
        }
        else if(m[str2]){
            m[str1] = true;
        }
    }
    map<string, bool>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        if(it->second){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}