#include <iostream>
using namespace std;

int main() {
    int count[26] = { 0, };
    int max = 0;
    char a;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] - 'a' + 'A';
        }
        count[s[i] - 'A']++;
    }
    for(int i = 0; i < 26; i++){
        if(count[i] > max){
            max = count[i];
            a = 'A' + i;
        }
    }
    int dup = 0;
    for(int i = 0; i < 26; i++){
        if(count[i] == max){
            dup++;
        }
    }
    if(dup >= 2) cout << "?";
    else cout << a;
    
    return 0;
}