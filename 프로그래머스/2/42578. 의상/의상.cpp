#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> mp;
    for(int i = 0; i < clothes.size(); i++){
        mp[clothes[i][1]]++;
    }

    int answer = 1;
    map<string, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        answer *= (it->second + 1);
    }
    answer--;

    return answer;
}