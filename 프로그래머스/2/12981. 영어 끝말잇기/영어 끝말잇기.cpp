#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, int> mp;
    vector<int> answer;
    char c = words[0][0];
    bool flag = false;
    for(int i = 0; i < words.size(); i++){
        if(words[i][0] != c || mp[words[i]] > 0){
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            flag = true;
            break;
        }
        mp[words[i]]++;
        int l = words[i].size();
        c = words[i][l - 1];
    }
    if(!flag){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}