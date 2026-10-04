#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, char> prev;
    for(int i = 1; i < skill.size(); i++){
        prev[skill[i]] = skill[i - 1];
    }
    for(int i = 0; i < skill_trees.size(); i++){
        map<char, int> learned;
        for(int j = 0; j < skill_trees[i].size(); j++){
            if(prev.find(skill_trees[i][j]) == prev.end() || learned.find(prev[skill_trees[i][j]]) != learned.end()){
                learned[skill_trees[i][j]]++;
            }
            else{
                answer++;
                break;
            }
        }
        
    }
    return skill_trees.size() - answer;
}