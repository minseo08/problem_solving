#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool visited_1[21];
bool visited_2[21];
int cnt = 0;

void dfs(vector<int> &numbers, int t, int index, int num){
    if(index == numbers.size() - 1){
        if(num == t)
            cnt++;
        return;
    }
    int tmp_plus = num;
    int tmp_minus = num;
    dfs(numbers, t, index + 1, num + numbers[index + 1]);
    dfs(numbers, t, index + 1, num - numbers[index + 1]);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, numbers[0]);
    dfs(numbers, target, 0, -numbers[0]);
    answer = cnt;
    return answer;
}