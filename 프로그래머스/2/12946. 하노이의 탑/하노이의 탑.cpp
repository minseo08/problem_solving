#include <string>
#include <vector>
#include <iostream>

using namespace std;

void hanoi(int start, int dest, int tmp, int total, vector<vector<int>>& answer){
    if(total == 0)
        return;
    
    hanoi(start, tmp, dest, total - 1, answer);
    
    vector<int> vec;
    vec.push_back(start);
    vec.push_back(dest);
    answer.push_back(vec);
    
    hanoi(tmp, dest, start, total - 1, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(1, 3, 2, n, answer);
    return answer;
}