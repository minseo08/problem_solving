#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    string st1 = "12345";
    string st2 = "21232425";
    string st3 = "3311224455";
    
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == st1[i % 5] - '0')
            num1++;
        if(char(answers[i]) == st2[i % 8] - '0')
            num2++;
        if(char(answers[i]) == st3[i % 10] - '0')
            num3++;
    }
    int tmp[3] = {num1, num2, num3};
    int m = max(num3, max(num1, num2));
    
    vector<int> answer;
    for(int i = 0; i <= 2; i++){
        if(tmp[i] == m)
            answer.push_back(i + 1);
    }
    
    return answer;
}