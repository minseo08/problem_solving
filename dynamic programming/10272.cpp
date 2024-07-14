#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, t, x, y;
pair<int, int> arr[513];
double dp[515][515];

double dist(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double func(int a, int b){
    if (a == n){
        return dist(arr[b].first, arr[b].second, arr[n].first, arr[n].second);
    }
    else if(b == n){
        return dist(arr[a].first, arr[a].second, arr[n].first, arr[n].second);
    }
    if(dp[a][b]){
        return dp[a][b];
    }    
    int next = max(a, b) + 1;
    dp[a][b] = min(func(a, next) + dist(arr[b].first, arr[b].second, arr[next].first, arr[next].second), func(next, b) + dist(arr[a].first, arr[a].second, arr[next].first, arr[next].second));
    return dp[a][b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            cin >> x >> y;
            arr[i].first = x;
            arr[i].second = y;
        }
        func(1, 1);
        cout.precision(20);
        cout << fixed << dp[1][1] << "\n";
    }
    return 0;
}