#include <iostream>
#include <algorithm>
using namespace std;
int zero_cnt(long long a, long long b){
    int cnt = 0;
    for(long long i = b; i <= a; i *= b){
        cnt += a / i;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a, b;
    cin >> a >> b;
    
    int c = zero_cnt(a, 5) - zero_cnt(a - b, 5) - zero_cnt(b, 5);
    int d = zero_cnt(a, 2) - zero_cnt(a - b, 2) - zero_cnt(b, 2);
    cout << min(c, d);
    return 0;
}