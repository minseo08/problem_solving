#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calculate(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

long long solution(string expression) {
    vector<long long> num;
    vector<char> op;
    long long answer = 0;
    
    string tmp = "";
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            num.push_back(stoll(tmp));
            tmp = "";
            op.push_back(expression[i]);
        }
        else{
            tmp += expression[i];
        }
    }
    num.push_back(stoll(tmp));
    
    vector<char> ops = {'+', '-', '*'};
    sort(ops.begin(), ops.end());
    
    bool flag = true;
    while(flag){ //6번
        vector<long long> tmp_num;
        vector<char> tmp_op;
        for(int i = 0; i < num.size(); i++)
            tmp_num.push_back(num[i]);
        for(int i = 0; i < op.size(); i++)
            tmp_op.push_back(op[i]);
        
        for(int i = 0; i < ops.size(); i++){ //특정 연산자 ops[i]에 대해
            for(int j = 0; j < tmp_op.size();){
                if(ops[i] == tmp_op[j]){
                    tmp_num[j] = calculate(tmp_num[j], tmp_num[j + 1], ops[i]);
                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_op.erase(tmp_op.begin() + j);
                }
                else{
                    j++;
                }
            }
        }
        answer = max(answer, abs(tmp_num[0]));
        if(!next_permutation(ops.begin(), ops.end()))
            flag = false;
    }

    return answer;
}

//기존 문자열 살리면서도 저장 가능
//operation 함수 따로 두고 모든 경우에서 사용