#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[201][201];
bool explode[201][201];
int r, c, n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    cin >> r >> c >> n;
    for(int j = 0; j < r; j++){
        string str;
        cin >> str;
        for(int k = 0; k < c; k++){
            if(str[k] == '.'){
                arr[j][k] = -1;
            }
            else{
                arr[j][k] = 1;
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                if(arr[j][k] == -1){
                    arr[j][k] = 1;
                }
                else
                    arr[j][k]--;
            }
        }
        i++;
        if(i >= n)
            break;
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                if(arr[j][k] == 0)
                    explode[j][k] = true;
                else
                    explode[j][k] = false;
            }
        }
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                if(!explode[j][k])
                    continue;
                arr[j][k] = -1;
                for(int l = 0; l < 4; l++){
                    if(j + dx[l] >= 0 && j + dx[l] <= r && k + dy[l] >= 0 && k + dy[l] <= c)
                        arr[j + dx[l]][k + dy[l]] = -1;
                }
            }
        }
    }
    for(int j = 0; j < r; j++){
        for(int k = 0; k < c; k++){
            if(arr[j][k] >= 0)
                cout << 'O';
            else
                cout << '.';
        }
        cout << "\n";
    }
    return 0;
}