#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
    long long n, m;
    cin >> n >> m;
    for(long long i = 0; i < n; i++){
        long long num;
        cin >> num;
        pq.push(num);
    }
    for(long long i = 0; i < m; i++){
        long long a = pq.top();
        pq.pop();
        long long sum = a + pq.top();
        pq.pop();
        pq.push(sum);
        pq.push(sum);
    }
    long long res = 0;
    while(!pq.empty()){
        res += pq.top();
        pq.pop();
    }
    cout << res;
    return 0;
}