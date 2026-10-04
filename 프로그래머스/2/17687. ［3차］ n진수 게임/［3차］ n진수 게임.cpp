#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
char dict[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string change(int num, int jin){
    if(num == 0)
        return "0";
    string str = "";
    while(num > 0){
        str += dict[num % jin];
        num /= jin;
    }
    reverse(str.begin(), str.end());
    return str;
}

string solution(int n, int t, int m, int p) {
    string tmp  = "";
    for(int i = 0; i <= t * m; i++){
        tmp += change(i, n);
    }
    string answer = "";
    for(int i = p - 1; i < t * m; i += m){
        answer += tmp[i];
    }
    return answer;
}