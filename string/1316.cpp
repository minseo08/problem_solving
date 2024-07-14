#include <iostream>
#include <string>
using namespace std;
//continue = 해당 loop 하나를 건너뜀
//break = 반복전체를 중단

int main() {
    int n;
    int count = 0;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        bool alphabet[26] = { false, };
        alphabet[s[0] - 'a'] = true;
        for(int j = 1; j < s.length(); j++){
            if(s[j] == s[j - 1]){
                continue;
            }
            else if(s[j] != s[j - 1] && alphabet[s[j] - 'a'] == true){
                count++;
                break;
            }
            else{
                alphabet[s[j] - 'a'] = true;
            }
        }
    }
    cout << n - count;

    return 0;
}