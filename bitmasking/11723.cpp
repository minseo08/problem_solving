#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "";
    int m, x;
    int s = 0;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> str;
        if(str == "add"){
            cin >> x;
            s |= (1 << x);
        }
        else if(str == "remove"){
            cin >> x;
            s &= ~(1 << x);
        }
        else if(str == "check"){
            cin >> x;
            if(s & (1 << x)){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if(str == "toggle"){
            cin >> x;
            if(s & (1 << x)){
                s &= ~(1 << x);
            }
            else{
                s |= (1 << x);
            }
        }
        else if(str == "all"){
            s = (1 << 21) - 1;
        }
        else if(str == "empty"){
            s = 0;
        }
    }
    return 0;
}