#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int result[2];

void func(int sx, int sy, int d, vector<vector<int>> &arr){
    if(d == 0)
        return;
    int tmp_int = arr[sx][sy];
    bool flag = false;
    for(int i = sx; i < sx + d; i++){
        for(int j = sy; j < sy + d; j++){
            if(arr[i][j] != tmp_int){
                flag = true;
            }
        }
    }
    if(flag){
        func(sx, sy, d/2, arr);
        func(sx + d/2, sy, d/2, arr);
        func(sx, sy + d/2, d/2, arr);
        func(sx + d/2, sy + d/2, d/2, arr);
    }
    else{
        result[tmp_int]++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    int n = arr[0].size();
    func(0, 0, n, arr);
    
    vector<int> answer;
    answer.push_back(result[0]);
    answer.push_back(result[1]);
    return answer;
}