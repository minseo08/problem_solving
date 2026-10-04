#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[1001][1001];
bool visited[1001][1001];
bool inbound[1001][1001];
int cnt  = 1;

void coloring(int x, int y){
    visited[x][y] = true;
    arr[x][y] = cnt;
    return;
}

int total(int num){
    int sum = 0;
    for(int i = num; i >= 1; i--)
        sum += i;
    return sum;
}

vector<int> solution(int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            inbound[i][j] = true;
        }
    }
    vector<int> answer;
    int x = 0;
    int y = 0;
    coloring(x, y);
    while(cnt <= total(n)){
        if((!inbound[x - 1][y - 1] || visited[x - 1][y - 1]) && inbound[x + 1][y] && !visited[x + 1][y]){
            cnt++;
            coloring(x + 1, y);
            x++;
            
            continue;
        }
        else if((!inbound[x + 1][y] || visited[x + 1][y]) && inbound[x][y + 1] && !visited[x][y + 1]){
            cnt++;
            coloring(x, y + 1);
            y++;
            continue;
        }
        else if((!inbound[x][y + 1] || visited[x][y + 1]) && inbound[x - 1][y - 1] && !visited[x - 1][y - 1]){
            cnt++;
            coloring(x - 1, y - 1);
            x--;
            y--;
            continue;
        }
        else
            break;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}