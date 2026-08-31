#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mw, mh;

int solution(vector<vector<int>> sizes) {
    
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        mw = max(mw, sizes[i][0]);
        mh = max(mh, sizes[i][1]);
    }
    int answer = mw * mh;
    return answer;
}