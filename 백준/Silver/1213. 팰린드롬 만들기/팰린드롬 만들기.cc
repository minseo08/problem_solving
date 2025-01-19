#include <iostream>
#include <string>
#include <algorithm>
#define MAX 52
using namespace std;
int alphabet[MAX + 1];
string str, tmp_str, res_str;
bool flag;
//A:65, a:97

int main(){
    int cnt = 0;
    string mid;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        alphabet[str[i] - 'A']++;
    }
    for(int i = 0; i < MAX; i++){
        int tmp = alphabet[i];
        if(tmp % 2 == 1){
            cnt++;
            if(cnt >= 2){
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            mid += char(i + 'A');
            alphabet[i]--;
        }
        if(tmp){
            for(int j = 0; j < tmp / 2; j++){
                tmp_str += char(i + 'A');
            }
        }
    }
    res_str = tmp_str;
    reverse(tmp_str.begin(), tmp_str.end());
    res_str += mid;
    for(int i = 0; i < tmp_str.size(); i++){
        res_str += tmp_str[i];
    }
    cout << res_str;
    
    return 0;
}