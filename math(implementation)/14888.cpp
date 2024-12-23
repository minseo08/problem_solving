#include <iostream>
using namespace std;
int num[12];
int op[4];
int res_max = -1000000001;
int res_min = 1000000001;
int n;

void func(int res, int cnt){
    if(cnt == n){
        if(res > res_max)
            res_max = res;
        if(res < res_min)
            res_min = res;
        return;
    }
    for(int i = 0; i < 4; i++){
        op[i]--;
        if(i == 0 && op[i] >= 0){
                func(res + num[cnt], cnt + 1);
        }
        if(i == 1 && op[i] >= 0){
                func(res - num[cnt], cnt + 1);
        }
        if(i == 2 && op[i] >= 0){
                func(res * num[cnt], cnt + 1);
        }
        if(i == 3 && op[i] >= 0){
                func(res / num[cnt], cnt + 1);
        }
        op[i]++;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }
    func(num[0], 1);
    cout << res_max << "\n";
    cout << res_min << "\n";
    return 0;
}