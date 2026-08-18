#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> bridge;
    int curr_weight = 0;
    int answer = 0;
    int idx = 0;

    while (idx < truck_weights.size()) {
        answer++;
        if(!bridge.empty() && bridge.front().second == answer) {
            curr_weight -= bridge.front().first;
            bridge.pop();
        }

        if(curr_weight + truck_weights[idx] <= weight && bridge.size() + 1 <= bridge_length) {
            curr_weight += truck_weights[idx];
            bridge.push({truck_weights[idx], answer + bridge_length});
            idx++;
        }
    }
    return bridge.back().second;
}