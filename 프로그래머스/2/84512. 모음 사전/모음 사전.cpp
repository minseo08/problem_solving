#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string alphabet[5] = {"A", "E", "I", "O", "U"};
bool visited[5];
vector<string> result;
map<string, int> mp;
int cnt;

void dfs(string str){
    cnt++;
    mp[str] = cnt;
    result.push_back(str);
    if(str.size() == 5)
        return;
    for(int i = 0; i < 5; i++){
        dfs(str + alphabet[i]);
    }
}

int solution(string word) {
    for(int i = 0; i < 5; i++){
        dfs(alphabet[i]);
    }
    
    int answer = mp[word];
    return answer;
}