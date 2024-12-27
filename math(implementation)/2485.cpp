#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int dist[100001];

int euclid(int a, int b){
    int r = a % b;
    if(r == 0)
        return b;
    else
        return euclid(b, r);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n - 1; i++){
        dist[i] = arr[i + 1] - arr[i];
    }
    int gcd = dist[0];
    for(int i = 1; i < n - 1; i++){
        gcd = euclid(gcd, dist[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        cnt += (dist[i] / gcd) - 1;
    }
    cout << cnt;
    return 0;
}