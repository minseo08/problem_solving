#include <iostream>
#include <cstring>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    string b;
    string t = "";
    bool flag = false;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++){
        t += a[i];
        if(t.length() >= b.length()){
            flag = true;
            for(int j = 0; j < b.length(); j++){
                if(t[t.length() - b.length() + j] != b[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                t.erase(t.end() - b.length(), t.end());
            }
        }
    }
    if(t.empty()){
        cout << "FRULA" << "\n";
    }
    else{
        cout << t << "\n";
    }
    return 0;
}