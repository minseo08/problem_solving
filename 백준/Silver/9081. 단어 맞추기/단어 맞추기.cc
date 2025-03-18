#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string str;
        cin >> str;
        if(!next_permutation(str.begin(), str.end())){
            prev_permutation(str.begin(), str.end());
        }
        for(int j = 0; j < str.size(); j++){
            cout << str[j];
        }
        cout << "\n";
    }
    return 0;
}