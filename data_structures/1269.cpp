#include <iostream>
#include <map>
using namespace std;
map<int, bool> mp;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        int a;
        cin >> a;
        if(mp[a] == true)
            mp.erase(a);
        else
            mp[a] = true;
    }
    cout << mp.size();
    return 0;
}