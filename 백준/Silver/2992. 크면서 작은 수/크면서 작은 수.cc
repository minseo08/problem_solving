#include <iostream>
#include <string>
#define INF 987654321
using namespace std;
string str;
int res;
int min_num = INF;
int num;

void func(int a, int num){
    for(int i = a; i >= 1; i--){
        for(int j = i - 1; j >= 0; j--){
            char tmp;
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            int n = stoi(str);
            if(n > num && n < min_num){
                res = n;
                min_num = res;
            }
            func(a - 1, num);
            str[j] = str[i];
            str[i] = tmp;
        }
    }
}

int main(){
    cin >> str;
    int num = stoi(str);
    func(str.size() - 1, num);
    cout << res;
    return 0;
}