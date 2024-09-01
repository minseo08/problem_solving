#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int> pq;
 
int main(){
    vector<int> res;
    int n, x;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x != 0){
            pq.push(x);
        }
        else{
            if(pq.empty()){
                res.push_back(0);
            }
            else{
                res.push_back(pq.top());
                pq.pop();
            }
        }
    }
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << "\n";
    }
    return 0;
}