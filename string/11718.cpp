#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while(1){
        getline(cin, str);
        cout << str << endl;
        if(str == ""){
            break;
        }
    }
    return 0;
}