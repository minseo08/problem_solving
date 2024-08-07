#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int pre[1001];
int in[1001];

void pos(int start, int end, int tmp){
    for(int i = start; i < end; i++){
        if(in[i] == pre[tmp]){
            pos(start, i, tmp + 1);
            pos(i + 1, end, tmp + 1 + i - start);
            cout << pre[tmp] << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, a, b;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> pre[j];
        }
        for(int j = 0; j < n; j++){
            cin >> in[j];
        }
        pos(0, n, 0);
        cout << "\n";
        memset(pre, 0, n);
        memset(in, 0, n);
    }
    return 0;
}
//pre는 맨 위부터
//in은 왼쪽부터
//post는 맨 아래부터