#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> result1;
vector<int> result2;

bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

void func(vector<vector<int>> &nodeinfo){
    if(nodeinfo.empty()){
        return;
    }
    int root_node = 0;
    int root_y = -1;
    int root_idx = 0;
    for(int i = 0; i < nodeinfo.size(); i++){
        if(root_y < nodeinfo[i][1]){
            root_idx = i;
            root_y = nodeinfo[i][1];
            root_node = nodeinfo[i][2];
        }
    }
    result1.push_back(root_node);
    vector<vector<int>> left;
    for(int i = 0; i < root_idx; i++){
        left.push_back(nodeinfo[i]);
    }
    vector<vector<int>> right;
    for(int i = root_idx + 1; i < nodeinfo.size(); i++){
        right.push_back(nodeinfo[i]);
    }
    func(left);
    func(right);
    result2.push_back(root_node);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int i = 0; i < nodeinfo.size(); i++){
        nodeinfo[i].push_back(i + 1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    func(nodeinfo);
    
    vector<vector<int>> answer;
    answer.push_back(result1);
    answer.push_back(result2);
    
    return answer;
}
// y기준으로 정렬