#include <iostream>
#include <string>
using namespace std;

int main() {
    int a;
    cin >> a;
    string str = to_string(a);
    for(int i = str.length() - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(str[j] < str[j + 1]){
                int tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < str.length(); i++){
        cout << str[i];
    }
    return 0;
}