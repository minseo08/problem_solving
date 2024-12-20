#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 0){
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << '0' << "\n";
        }
        else
            pq.push(a);
    }
    return 0;
}