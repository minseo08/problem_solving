#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> crane;
vector<int> box;

int main(){
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        crane.push_back(tmp);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int tmp;
        cin >> tmp;
        box.push_back(tmp);
    }
    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    if(crane[0] < box[0]){
        cout << "-1";
        return 0;
    }
    int res = 0;
    while(!box.empty()){
        res++;
        for(int i = 0; i < crane.size(); i++){
            for(int j = 0; j < box.size(); j++){
                if(crane[i] >= box[j]){
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    cout << res;
    return 0;
}