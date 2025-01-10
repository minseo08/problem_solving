#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string arr[60];
vector<string> res;

int main(){
    int t, m, n, cnt = 0;
    cin >> t >> m >> n;
    for(int i = 0; i < t; i++){
        string str;
        cin >> str;
        while(1){
            int time;
            cin >> time;
            if(time == -1)
                break;
            arr[time] = str;
        }
    }
    for(int i = m; i < 60; i++){
        if(arr[i] != "")
            res.push_back(arr[i]);
    }
    for(int i = 0; i < m; i++){
        if(arr[i] != "")
            res.push_back(arr[i]);
    }
    int tmp = (n - 1) % res.size();
    cout << res[tmp];
    return 0;
}