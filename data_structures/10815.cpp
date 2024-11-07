#include <iostream>
#include <map>
using namespace std;
map<int, bool> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        mp.insert({a, true});
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int b;
        cin >> b;
        cout << mp[b] << " ";
    }
    return 0;
}