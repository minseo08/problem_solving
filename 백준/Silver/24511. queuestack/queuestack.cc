#include <iostream>
#include <queue>
using namespace std;
int arr[100001];
deque<int> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(!arr[i])
            dq.push_front(tmp);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        dq.push_back(num);
        cout << dq.front() << " ";
        dq.pop_front();
    }
    return 0;
}