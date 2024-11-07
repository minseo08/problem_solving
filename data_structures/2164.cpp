#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    int i = 1;
    while(q.size() > 1){
        if(i % 2 == 1){
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
        i++;
    }
    cout << q.front();
    return 0;
}
//버리기, 아래에 놓기 반복