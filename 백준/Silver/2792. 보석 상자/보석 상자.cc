#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> vec;
long long n, m;

bool func(long long curr){
    long long res = 0;
    for(long long i = 0; i < m; i++){
        res += vec[i] / curr;
        if(vec[i] % curr)
            res++;
    }
    return n >= res;
}

int main(){
    cin >> n >> m;
    for(long long i = 0; i < m; i++){
        long long num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    long long st = 1;
    long long end = vec[m - 1];
    long long mid = 0;
    long long ans = vec[m - 1];
    while(st < end){
        mid = (st + end) / 2;
        if(func(mid)){
            if(ans > mid)
                ans = mid;
            end = mid;
        }
        else
            st = mid + 1;
    }
    cout << ans;
    
    return 0;
}