#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int cnt = 0;
    cin >> n;
    for(int i = 5; i <= n; i *= 5)
        cnt += n / i;
    cout << cnt << "\n";
    return 0;
}