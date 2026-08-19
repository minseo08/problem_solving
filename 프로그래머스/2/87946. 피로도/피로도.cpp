#include <string>
#include <vector>
#include <iostream>

using namespace std;
int total;
bool visited[5001];
int result[5001];
int tmp;
int answer;

void dfs(int num, int cnt, int k, vector<vector<int>> dungeons){
    visited[num] = true;
    result[cnt] = num;
    if(cnt == total - 1){
        tmp = 0;
        for(int i = 0; i < total; i++){
            if(k >= dungeons[result[i]][0]){
                k -= dungeons[result[i]][1];
                tmp++;
                answer = max(answer, tmp);
            }
            else
                break;
        }
        return;
    }
    for(int i = 0; i < total; i++){
        if(!visited[i]){
            dfs(i, cnt + 1, k, dungeons);
            visited[i] = false;
        }
    }
    visited[num] = false;
}

int solution(int k, vector<vector<int>> dungeons) {
    total = dungeons.size();
    for(int i = 0; i < total; i++){
        dfs(i, 0, k, dungeons);
    }
    return answer;
}