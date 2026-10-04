#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int result[1000001];

vector<int> solution(string s) {
    string tmp;
    map<int, int> mp;
    bool flag = false;
    int cnt = 0;
    for(int i = 1; i < s.size() - 1; i++){
        if(s[i] == '{'){
            flag = true;
            continue;
        }
        if(s[i] == '}'){
            cnt++;
            stringstream ss(tmp);
            string num;
            while(getline(ss, num, ',')){
                mp[stoi(num)]++;
            }
            flag = false;
            tmp = "";
            continue;
        }
        if(flag){
            tmp += s[i];
        }
    }
    vector<int> answer(cnt);
    map<int, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        answer[it->second - 1] = it->first;
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}