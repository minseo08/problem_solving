#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int res[10001];

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for(int i = 0; i < citations.size(); i++)
        res[citations[i]] = n - i;
    int answer = 0;
    for(int i = citations.size() - 1; i >= 0; i--){
        int cit = citations[i];
        //cout << res[cit] << " " << cit << "\n";
        if(res[cit] <= cit)
            answer++;
        else
            break;
    }
        
    return answer;
}