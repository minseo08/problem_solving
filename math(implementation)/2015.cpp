#include <iostream>
#include <map>
using namespace std;
long long arr[200001];
map<long long, long long> m;

int main(){
    long long n, res = 0;
    long long k, sum = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        long long a;
        cin >> a;
        arr[i] = sum + a;
        sum += a;
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            res++;
        }
        res += m[arr[i] - k];
        m[arr[i]]++;
    }
    cout << res;
    return 0;
}