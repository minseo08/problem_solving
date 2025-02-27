#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        vector<int> vec_a;
        vector<int> vec_b;
        int n, m, res = 0;
        cin >> n >> m;
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            vec_a.push_back(a);
        }
        for(int j = 0; j < m; j++){
            int b;
            cin >> b;
            vec_b.push_back(b);
        }
        sort(vec_a.begin(), vec_a.end());
        sort(vec_b.begin(), vec_b.end());
        for(int j = n - 1; j >= 0; j--){
            int pointer = 0;
            while(vec_a[j] > vec_b[pointer] && pointer < m){
                pointer++;
            }
            res += pointer;
        }
        cout << res << "\n";
        
    }
    return 0;
}