#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;

void order(int st, int end){
    if(st > end)
        return;
    if(st == end){
        cout << vec[st] << "\n";
        return;
    }
    int cur = st + 1;
    while(cur <= end){
        if(vec[st] < vec[cur]){
            break;
        }
        cur++;
    }
    order(st + 1, cur - 1);
    order(cur, end);
    cout << vec[st] << "\n";    
}
int main(){
    int a;
    while(cin >> a){
        vec.push_back(a);
    }
    order(0, vec.size() - 1);
    return 0;
}