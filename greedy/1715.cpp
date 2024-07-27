#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    int res = 0;
    while(pq.size() > 1){
        int sum = 0;
        int tmp = pq.top();
        pq.pop();
        sum = tmp + pq.top();
        pq.pop();
        pq.push(sum);
        res += sum;
    }    
    cout << res;
    return 0;
}