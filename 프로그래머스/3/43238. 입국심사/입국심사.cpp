#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 9876543210

using namespace std;

long long solution(int n, vector<int> times) {
    // int ind = -1;
    // long long tmp = INF;
    // for(int i = 0; i < times.size(); i++){
    //     if(tmp > times[i]){
    //         tmp = times[i];
    //         ind = i;
    //     }
    //     arr[i] = times[i];
    //     n--;
    // }
    // for(int j = 0; j < n; j++){
    //     int ind_2 = -1;
    //     long long tmp_2 = INF;
    //     for(int i = 0; i < times.size(); i++){    
    //         if(tmp_2 > arr[i] - arr[ind] + times[i]){
    //             ind_2 = i;
    //             tmp_2 = arr[i] - arr[ind] + times[i];
    //         }
    //     }
    //     arr[ind_2] += times[ind_2];
    //     for(int i = 0; i < times.size(); i++)
    //         cout << arr[i] << " ";
    //     cout << "\n";
    // }
    // sort(arr, arr + times.size(), greater());
    // long long answer = arr[0];
    // return answer;
    long long answer = 0;
    sort(times.begin(), times.end());
    long long left = 1;
    long long right = (long long)n * times[times.size() - 1];
    while(left <= right){
        long long tmp = 0;
        long long mid = (left + right) / 2;
        for(int i = 0; i < times.size(); i++){
            tmp += mid / times[i];
        }
        if(tmp >= n){
            right = mid - 1;
            answer = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return answer;
}