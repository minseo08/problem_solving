#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    while(1){
        if(t[t.length() - 1] == 'A'){
            t.pop_back();
        }
        else{
            t.pop_back();
            reverse(t.begin(), t.end());
        }
        if(t.length() == s.length()){
            if(t == s){
                cout << 1;
            }
            else{
                cout << 0;
            }
            break;
        }
    }
    return 0;
}