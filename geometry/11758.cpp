#include <iostream>
#include <algorithm>
using namespace std;
int dx[10001];
int dy[10001];

int main(){
    for(int i = 0; i < 3; i++){
        cin >> dx[i] >> dy[i];
    }
    int sum_1 = 0;
    int sum_2 = 0;
    for(int i = 0; i < 3; i++){
        sum_1 += dx[i] * dy[(i + 1) % 3];
        sum_2 += dx[(i + 1) % 3] * dy[i];
    }
    if(sum_1 - sum_2 < 0)
        cout << "-1";
    if(sum_1 - sum_2 > 0)
        cout << "1";
    if(sum_1 - sum_2 == 0)
        cout << "0";
    return 0;
}