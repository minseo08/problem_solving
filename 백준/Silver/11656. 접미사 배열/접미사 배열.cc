#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string> vec;

int main(){
    string str, ans;
    cin >> str;
    ans = str;
    while(ans.size()){
        ans = "";
        int j;
        for(int i = j; i < str.size(); i++){
            ans.push_back(str[i]);
        }
        vec.push_back(ans);
        j++;
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++)
        if(vec[i] != "")
            cout << vec[i] << "\n";
    return 0;
}