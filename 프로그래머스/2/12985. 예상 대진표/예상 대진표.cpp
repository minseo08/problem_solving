#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int total = 0;
    while(n >= 1){
        n /= 2;
        total++;
    }
    int answer = 0;
    while(total > 0 && abs(a - b) >= 1){
        if(a % 2)
            a += 1;
        if(b % 2)
            b += 1;
        
        a /= 2;
        b /= 2;
        total--;
        answer++;
    }

    return answer;
}