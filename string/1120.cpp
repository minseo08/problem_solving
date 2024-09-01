#include <iostream>
#include <string>
#include <algorithm>
#define INF 987654321
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    int ans = INF;
    for(int i = 0; i <= b.size() - a.size(); i++){
        int cnt = 0;
        for(int j = 0; j < a.size(); j++){
            if(a[j] != b[j + i]){
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}