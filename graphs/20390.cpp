#include <iostream>
#include <climits>
#include <vector>
using namespace std;
//__int128 long long 사용
#define INF LLONG_MAX
long long a, b, c, d;
long long x[10001];
bool visited[10001];

long long cal(long long q, long long w){
    if(q > w){
        long long tmp = q;
        q = w;
        w = tmp;
    }
    return (((__int128)x[q] * a + (__int128)x[w] * b) % c) ^ d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    cin >> a >> b >> c >> d;
    for(long long i = 0; i < n; i++){
        cin >> x[i];
    }
    long long res = 0;
    vector<long long> acc_dist(n, INF);
    acc_dist[0] = 0;
    for(long long i = 0; i < n; i++){
        long long curr = 0;
        long long mn = INF;
        for(long long j = 0; j < n; j++){
            if(!visited[j] && mn > acc_dist[j]){
                mn = acc_dist[j]; //비교를 위한 최소값
                curr = j;
            }
        }
        visited[curr] = true;
        res += acc_dist[curr];
        for(long long j = 0; j < n; j++){
            if(visited[j] || cal(curr, j) > acc_dist[j]){
                continue;
            }
            acc_dist[j] = cal(curr, j);
        }
    }
    cout << res;
    return 0;
}