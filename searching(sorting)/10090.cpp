#include <iostream>
using namespace std;
int arr[1000001];
int tmp[1000001];
long long res;

void merge(int s, int m, int e){
    int a, b;
    int idx = 0;
    a = s;
    b = m;
    while(a < m && b < e){
        if(arr[a] < arr[b]){
            tmp[idx] = arr[a];
            idx++;
            a++;
        }
        else if(arr[a] > arr[b]){
            tmp[idx] = arr[b];
            res += m - a;
            idx++;
            b++;
        }
        else{
            tmp[idx] = arr[b];
            idx++;
            b++;
        }
    }
    while(a < m){
        tmp[idx] = arr[a];
        idx++;
        a++;
    }
    while(b < e){
        tmp[idx] = arr[b];
        idx++;
        b++;
    }
    for(int i = 0; i < e - s; i++){
        arr[s + i] = tmp[i];
    }
}

void merge_sort(int s, int e){
    int m = (s + e) / 2;
    if(s < m){
        merge_sort(s, m);
        merge_sort(m, e);
        merge(s, m, e);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    merge_sort(0, n);
    cout << res;
    return 0;
}