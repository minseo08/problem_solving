#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[201];

int ubak(int k){
    int cnt = 0;
    while(k > 1){
        cnt++;
        if(k % 2)
            k = 3 * k + 1;
        else
            k /= 2;
        arr[cnt] = k;
    }
    arr[cnt] = k;
    return cnt;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    int n = ubak(k);
    arr[0] = k;
    for(int i = 0; i < ranges.size(); i++){
        double sum = 0;
        if(ranges[i][0] <= n + ranges[i][1]){
            for(int j = ranges[i][0]; j <= n + ranges[i][1]; j++){
                sum += arr[j];
                if(j != ranges[i][0] && j != n + ranges[i][1])
                    sum += arr[j];
                if(j == ranges[i][0] && j == n + ranges[i][1])
                    sum = 0;
            }
            answer.push_back(sum / 2);
        }
        else{
            answer.push_back(-1);
        }
    }
    return answer;
}