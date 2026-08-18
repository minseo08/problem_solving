#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> mp;

bool solution(vector<string> phone_book) {
    for(int i = 0; i < phone_book.size(); i++){
        mp[phone_book[i]]++;
    }
    for(int i = 0; i < phone_book.size(); i++){
        for(int j = 1; j < phone_book[i].size(); j++){
            if(mp[phone_book[i].substr(0, j)]){
                return false;
            }
        }
    }
    bool answer = true;
    return answer;
}