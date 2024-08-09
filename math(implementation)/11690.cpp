#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_prime[100000001];

void prime(int n){
    for(int i = 2; i <= n; i++){
        is_prime[i] = true;
    }
    for(int i = 2; i * i <= n; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec;
    prime(n);
    vec.push_back(2);
    long long res = 1;
    for(int i = 3; i <= n; i++){
        if(is_prime[i]){
            vec.push_back(i);
        }
    }
    for(int i = 0; i < vec.size(); i++){
        long long a = vec[i];
        while(vec[i] * a <= n){
            a *= vec[i];
        }
        res = (res * a) % ((long long)1 << 32);
    }
    cout << res;
    return 0;
}