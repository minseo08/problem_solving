#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int cnt[21];

int solution(string name) {
    int answer = 0;
    int size = name.size();
    int m = 41;
    for(int i = 0; i < name.size(); i++){
        answer += min(name[i] - 'A', 'Z' + 1 - name[i]);
    }
    for(int i = 0; i < name.size(); i++){
        int j = i + 1;
        while(name[j] == 'A')
            j++;
        int cand_1 = i * 2 + size - j;
        int cand_2 = (size - j) * 2 + i;
        int cand_3 = size - 1;
        int tmp = min({cand_1, cand_2, cand_3});
        m = min(m, tmp);
    }
    answer += m;

    return answer;
}