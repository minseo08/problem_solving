#include <iostream>
using namespace std;
int arr[200001];
int n;

int cdg(int a, int b){
    return (a % b ? cdg(b, a % b) : b);
}

int func(int s, int e){
    int res = 0;
    for(int i = s; i <= e; i++){
        res = cdg(res, arr[i]);
    }
    return res;
}

int divide(int s, int e){
    if(s == e){
        return arr[s];
    }
    else {
        int mid = (e + s - 1) / 2;
        int val1 = func(s, mid) + divide(mid + 1, e);
        int val2 = func(mid + 1, e) + divide(s, mid);
        return max(val1, val2);
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << divide(0, n - 1);
    return 0;
}