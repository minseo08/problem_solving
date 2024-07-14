#include <iostream>
using namespace std;

int main() {
    string croatian[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s;
    cin >> s;
    for(int i = 0; i < 8; i++){
        while(1){
            if(s.find(croatian[i]) != -1){
                s.replace(s.find(croatian[i]), croatian[i].length(), "#");
            }
            else{
                break;
            }
        }
    }
    cout << s.length();

    return 0;
}