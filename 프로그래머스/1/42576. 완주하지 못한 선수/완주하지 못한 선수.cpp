#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> mp;
    for(int i = 0; i < participant.size(); i++){
        mp[participant[i]]++;
    }
    for(int i = 0; i < completion.size(); i++){
        mp[completion[i]]--;
    }
    string answer = "";
    unordered_map<string, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        if(it->second == 1)
            answer = it->first;
    }
    return answer;
}