#include <iostream>
#define INF 987654321
using namespace std;
long long cost[100001], dist[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> dist[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    int tmp = INF;
    long long sum = 0;
    for(int i = 1; i < n; i++){
        if(cost[i] < tmp){
            tmp = cost[i];
        }
        sum += (long long)tmp * dist[i];
    }
    cout << sum;
    
    return 0;
}