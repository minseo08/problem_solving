#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> mp;
string arr[11];
int n, k;
int id[11];
bool visited[11];

void comb(int s, int cnt){
    string res;
    if(cnt == k){
        for(int i = 0; i < k; i++){
            res += arr[id[i]];
        }
        mp[res]++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            id[cnt] = i;
            comb(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    comb(0, 0);
    cout << mp.size();
}