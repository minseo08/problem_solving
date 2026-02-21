#include <iostream>
#include <string>
using namespace std;

int main(){
    string str, tmp;
    bool hasMinus = false;
    cin >> str;
    int res = 0;
    for(int i = 0; i <= str.size(); i++){
        if(str[i] == '+' || str[i] == '-' || i == str.size()){
            if(hasMinus){
                res -= stoi(tmp);
                tmp = "";
            }
            else{
                res += stoi(tmp);
                tmp = "";
            }
            if(str[i] == '-'){
                hasMinus = true;
            }
        }
        else{
            tmp += str[i];
        }
    }
    cout << res;
}