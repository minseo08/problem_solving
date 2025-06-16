#include <iostream>
#include <string>
using namespace std;
string str;
int res;

bool ispalindrom(string str){
    int mid = str.size() / 2;
    for(int i = 0; i < mid; i++){
        if(str[i] != str[str.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> str;
    if(str.size() % 2)
        res = str.size() * 2 - 1;
    else
        res = str.size() * 2;
    for(int i = 0; i < str.size(); i++){
        if(ispalindrom(str.substr(i, str.size() - i))){
            res = str.size() + i;
            break;
        }
    }
    cout << res;
    return 0;
}