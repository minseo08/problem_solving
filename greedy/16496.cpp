#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str[1001];

bool cmp(string a, string b){
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n ; i++){
        cin >> str[i];
        if(str[i] != "0"){
            flag = true;
        }
    }
    if(!flag){
        cout << 0;
    }
    else{
        sort(str, str + n, cmp);
        for(int i = 0; i < n; i++){
            cout << str[i];
        }
    }
    return 0;
}