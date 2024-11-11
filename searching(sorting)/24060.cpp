#include <iostream>
using namespace std;
int arr[500001];
//int res[500001];
int n, king;
int num = 0;
void merge(int *arr, int s, int m, int e){
    int res[e - s + 1] = {0, };
    int i = s;
    int j = m + 1;
    int k = 0;
    while(i <= m && j <= e){
        if(arr[i] <= arr[j]){
            res[k] = arr[i];
            k++;
            i++;
        }
        else{
            res[k] = arr[j];
            k++;
            j++;
        }
    }
    if(i > m){
        while(j <= e){
            res[k] = arr[j];
            k++;
            j++;
        }
    }
    else{
        while(i <= m){
            res[k] = arr[i];
            k++;
            i++;
        }
    }
    for(i = s, k = 0; i <= e; i++, k++){
        arr[i] = res[k];
        num++;
        if(num == king)
            cout << arr[i];
    }
}

void mergesort(int *arr, int s, int e){
    if(s < e){
        int m = (s + e) / 2;
        mergesort(arr, s, m);
        mergesort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}

int main(){
    cin >> n >> king;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    if(num < king)
        cout << -1;
    return 0;
}