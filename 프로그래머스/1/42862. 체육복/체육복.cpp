#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool losted[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<bool> student(n + 1);
    for(int i = 1; i <= n; i++)
        student[i] = true;
    for(int i = 0; i < lost.size(); i++){
        losted[lost[i]] = true;
        student[lost[i]] = false;
    }
    sort(reserve.begin(), reserve.end());
    for(int i = 0; i < reserve.size(); i++){
        if(losted[reserve[i]] || !student[reserve[i]]){
            student[reserve[i]] = true;
            continue;
        }
        if(reserve[i] - 1 > 0 && !student[reserve[i] - 1]){
            student[reserve[i] - 1] = true;
            continue;
        }
        if(reserve[i] + 1 <= n && !student[reserve[i] + 1]){
            student[reserve[i] + 1] = true;
            continue;
        }
    }
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(student[i])
            answer++;
        cout << student[i] << " ";
    }

    return answer;
}