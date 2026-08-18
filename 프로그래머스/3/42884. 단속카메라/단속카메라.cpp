#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), cmp);
    int tmp = routes[0][1];
    
    for(int i = 0; i < routes.size(); i++){
        if(tmp >= routes[i][0])
            continue;
        else{
            tmp = routes[i][1];
            answer++;
        }
    }
    return answer;
}