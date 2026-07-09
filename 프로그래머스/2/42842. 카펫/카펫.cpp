#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int n = brown + yellow;
    int sero = 3;
    while(sero < (n / 2)){
        if(n % sero == 0){
            int garo = n / sero;
            if((garo-2) * (sero-2) == yellow){
                answer.push_back(garo);
                answer.push_back(sero);
                break;
            }
        }
        sero++;
    }
    return answer;
}