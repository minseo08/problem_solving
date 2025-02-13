#include <iostream>
#include <deque>
using namespace std;
deque<pair<int, int>> dq;
int arr[1001];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int mv;
        cin >> mv;
        dq.push_back({mv, i});
    }
    cout << dq.front().second << " ";
    for(int i = 1; i < n; i++){
        int mv = dq.front().first;
        dq.pop_front();
        if(mv > 0){
            for(int j = 0; j < mv - 1; j++){
                pair<int, int> tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
        }
        else{
            for(int j = 0; j < -mv; j++){
                pair<int, int> tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
        }
        cout << dq.front().second << " ";
    }
    return 0;
}