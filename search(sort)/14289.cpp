#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[51][51] = {};
ll rem[51][51] = {};
ll temp[51][51] = {};
ll n, m, a, b, d;

void squared(ll a[][51], ll b[][51]) {
    memset(temp, 0, sizeof(temp));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] %= 1000000007;
            }
        }
    }
    memcpy(arr, temp, sizeof(arr)); 
}


void reculs(ll x) {
    if (x == 1) return;
    if (x % 2 == 1) {
        reculs(x / 2);
        squared(arr, arr);
        squared(arr, rem);
    } else {
        reculs(x / 2);
        squared(arr, arr);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        arr[a][b] = 1; arr[b][a] = 1;
        rem[a][b] = 1; rem[b][a] = 1;
    }
    cin >> d;
    reculs(d); 
    cout << arr[0][0] << "\n"; 
}
