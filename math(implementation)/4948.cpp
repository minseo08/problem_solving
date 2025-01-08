#include <iostream>
#include <algorithm>
using namespace std;

void check_prime(long long n){
    int cnt = 0;
    bool arr[n * 2 + 1] = {0, 1, };
    for(long long i = 2; i <= n; i++){
        for(long long j = i; i * j <= 2 * n; j++){
            arr[i * j] = true;
        }
    }
    for(long long i = n + 1; i <= n * 2; i++){
        if(!arr[i])
            cnt++;
    }
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    while(cin >> n){
        if(n == 0)
            break;
        check_prime(n);

    }
    return 0;
}