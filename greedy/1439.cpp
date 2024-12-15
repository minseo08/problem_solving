#include <iostream>
#include <string>
using namespace std;
int res = 0;

int main(){
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != str[i + 1])
            res++;
    }
    cout << res / 2;
    return 0;
}