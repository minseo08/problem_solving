#include <iostream>
#include <vector>
#define SUDO 9
using namespace std;
int arr[SUDO][SUDO];
vector<pair<int, int>> vec;
bool func_end = false;

bool promise(int x, int y, int num){
    for(int i = 0; i < SUDO; i++){
        if(arr[x][i] == num)
            return false;
        if(arr[i][y] == num)
            return false;
    }
    int n_x = (x / 3) * 3;
    int n_y = (y / 3) * 3;
    for(int i = n_x; i < n_x + 3; i++){
        for(int j = n_y; j < n_y + 3; j++){
            if(arr[i][j] == num)
                return false;
        }
    }
    return true;
}

void func(int cur){
    if(func_end)
        return;
    if(cur == vec.size()){
        for(int i = 0; i < SUDO; i++){
            for(int j = 0; j < SUDO; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        func_end = true;
        return;
    }
    else{
        int x = vec[cur].first;
        int y = vec[cur].second;
        for(int j = 1; j <= SUDO; j++){
            if(promise(x, y, j)){
                arr[x][y] = j;
                func(cur + 1);
                arr[x][y] = 0;
            }
        }
    }
}

int main(){
    for(int i = 0; i < SUDO; i++){
        for(int j = 0; j < SUDO; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                vec.push_back({i, j});
        }
    }
    func(0);
    return 0;
}