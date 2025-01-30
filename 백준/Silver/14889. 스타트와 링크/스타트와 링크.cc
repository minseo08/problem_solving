#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;
int arr[21][21];
bool visited[21];
int n, r, res = INF;

void comb(int n, int r, int start, int cnt){
    if(cnt == r){
        int score_1 = 0;
        int score_2 = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i] && visited[j]){
                    score_1 += arr[i][j];
                }
                if(!visited[i] && !visited[j]){
                    score_2 += arr[i][j];
                }
            }
        }
        res = min(abs(score_1 - score_2), res);
    }
    for(int i = start; i < n; i++){
        visited[i] = true;
        comb(n, r, i + 1, cnt + 1);
        visited[i] = false;
    }
}

int main(){
    cin >> n;
    r = n / 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    comb(n, r, 0, 0);
    cout << res;
    return 0;
}