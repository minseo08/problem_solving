#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        priority_queue<long long> big;
        priority_queue<long long, vector<long long>, greater<long long>> small;
        vector<long long> res;
        int m;
        cin >> m;
        for(int j = 1; j <= m; j++){
            long long a;
            cin >> a;
            if(j % 2 != 0){
                big.push(a);
                if(!big.empty() && !small.empty() && big.top() > small.top()){
                    small.push(big.top());
                    big.pop();
                    big.push(small.top());
                    small.pop();
                }
                res.push_back(big.top());
            }
            else{
                small.push(a);
            }
        }
        cout << res.size() << "\n";
        for(int j = 0; j < res.size(); j++){
            cout << res[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}