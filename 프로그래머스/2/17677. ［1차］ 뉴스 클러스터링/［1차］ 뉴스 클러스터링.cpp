#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define MUL 65536
using namespace std;

int solution(string str1, string str2) {
    string tmp1 = "";
    for(int i = 0; i < str1.size(); i++){
        if(str1[i] >= 'a' && str1[i] <= 'z'){
            tmp1 += str1[i];
        }
        else if(str1[i] >= 'A' && str1[i] <= 'Z'){
            tmp1 += str1[i] + 32;
        }
        else
            tmp1 += ' ';
    }
    string tmp2 = "";
    for(int i = 0; i < str2.size(); i++){
        if(str2[i] >= 'a' && str2[i] <= 'z'){
            tmp2 += str2[i];
        }
        else if(str2[i] >= 'A' && str2[i] <= 'Z'){
            tmp2 += str2[i] + 32;
        }
        else
            tmp2 += ' ';
    }
    int total = 0;
    vector<string> vec;
    for(int i = 0; tmp1.size() > 1 && i < tmp1.size() - 1; i++){
        string tmp = tmp1.substr(i, 2);
        if(tmp.find(' ') == string::npos){
            total++;
            vec.push_back(tmp);
        }
    }
    int cnt = 0;
    for(int i = 0; tmp2.size() > 1 && i < tmp2.size() - 1; i++){
        string tmp = tmp2.substr(i, 2);
        if(tmp.find(' ') == string::npos){
            vector<string>::iterator it = find(vec.begin(), vec.end(), tmp);
            if(it != vec.end()){
                vec.erase(it);
                cnt++;
            }
            else
                total++;
        }
    }
    if(!total)
        return MUL;
    int answer = cnt * MUL / total;
    return answer;
}

//map 사용 실패했지만, 아래 같이 둘중 작은 개수로(min) 사용 가능

// int solution(string str1, string str2) {
//     unordered_map<string, int> m1, m2;
//     int total_elements_1 = 0, total_elements_2 = 0;

//     // 1. str1에서 곧바로 2글자씩 검사하며 map에 카운트 (공백 채우기 X)
//     for (int i = 0; i < (int)str1.size() - 1; i++) {
//         if (isalpha(str1[i]) && isalpha(str1[i+1])) {
//             string tmp = "";
//             tmp += tolower(str1[i]);
//             tmp += tolower(str1[i+1]);
//             m1[tmp]++;
//             total_elements_1++; // str1의 총 유효 원소 개수
//         }
//     }

//     // 2. str2도 똑같이 처리
//     for (int i = 0; i < (int)str2.size() - 1; i++) {
//         if (isalpha(str2[i]) && isalpha(str2[i+1])) {
//             string tmp = "";
//             tmp += tolower(str2[i]);
//             tmp += tolower(str2[i+1]);
//             m2[tmp]++;
//             total_elements_2++; // str2의 총 유효 원소 개수
//         }
//     }

//     // 3. 두 집합이 모두 공집합인 경우 예외 처리
//     if (total_elements_1 == 0 && total_elements_2 == 0) return MUL;

//     // 4. 교집합(cnt) 구하기: m1과 m2에 동시에 존재하는 키의 최소값 누적
//     int cnt = 0;
//     for (auto const& [key, val] : m1) {
//         if (m2.count(key)) {
//             cnt += min(val, m2[key]);
//         }
//     }

//     // 5. 합집합(total) 공식 적용
//     int total = total_elements_1 + total_elements_2 - cnt;

//     return cnt * MUL / total;
// }
