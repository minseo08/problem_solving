#include <string>
#include <iostream>
#include <vector>

using namespace std;

int func(int n){
    string str = "";
    while(n >= 1){
        str += '0' + (n % 2);
        n = n / 2;
    }
    str += '0' + n;
    int answer = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '1')
            answer++;
    }
    return answer;
}

int solution(int n) {
    int answer = n + 1;
    while(func(answer) != func(n)){
        answer++;
    }
    
    return answer;
}