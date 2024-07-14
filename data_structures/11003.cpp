#include <iostream>
#include <queue>
using namespace std;
//우선수위큐
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        pq.push(make_pair(num, i));
        while(pq.top().second < i - l + 1){
            pq.pop();
        }
        cout << pq.top().first << " ";
    }
    return 0;
}