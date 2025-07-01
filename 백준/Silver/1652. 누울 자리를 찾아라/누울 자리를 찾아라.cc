#include <iostream>
#include <string>
using namespace std;
string arr[101];
int ga, se;

int main(){
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        bool is_ga = false;
        for(int j = 0; j < n; j++){
            if(is_ga){
                if(arr[i][j + 1] == 'X')
                    is_ga = false;
                else
                    continue;
            }
            if(arr[i][j] == '.' && arr[i][j + 1] == '.'){
                ga++;
                is_ga = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        bool is_se = false;
        for(int j = 0; j < n; j++){
            if(is_se){
                if(arr[j + 1][i] == 'X')
                    is_se = false;
                else
                    continue;
            }
            if(arr[j][i] == '.' && arr[j + 1][i] == '.'){
                se++;
                is_se = true;
            }
        }
    }
    cout << ga << " " << se;
    return 0;
}