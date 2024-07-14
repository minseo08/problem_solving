#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    string res;
    bool start = false;
    for(int i = 0; i < str.length(); i++){
        res += to_string((str[i] - '0') / 4);
        res += to_string(((str[i] - '0') % 4) / 2);
        res += to_string((((str[i] - '0') % 4) % 2) / 1);
    }
    for(int i = 0; i < res.length(); i++){
        if(!start){
            if(res[i] == '1'){
                cout << res[i];
                start = true;
            }
            else if(i == res.length() - 1)
                cout << res[i];
        }
        else
            cout << res[i];
    }
    return 0;
}