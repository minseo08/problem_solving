#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int dp[101][101];
int dp_2[101][101];
vector<int> vec;
void route(int s, int e){
    if(dp_2[s][e] == 0){
        vec.push_back(s);
        vec.push_back(e);
    }
    else{
        route(s, dp_2[s][e]);
        vec.pop_back();
        route(dp_2[s][e], e);
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INF;
            }
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }
    for(int a = 1; a <= n; a++){
        for(int b = 1; b <= n; b++){
            for(int c = 1; c <= n; c++){
                if(dp[b][a] + dp[a][c] < dp[b][c]){
                    dp[b][c] = dp[b][a] + dp[a][c];
                    dp_2[b][c] = a;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == INF){
                cout << "0" << " ";
            }
            else{
                cout << dp[i][j] << " ";
            }
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == 0 || dp[i][j] == INF){
                cout << "0" << "\n";
            }
            else{
                vec.clear();
                route(i, j);
                cout << vec.size() << " ";
                for(int k = 0; k < vec.size(); k++){
                    cout << vec[k] << " ";
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}