#include <iostream>
#define MAX 1000000

using namespace std;
int sosu[MAX] = { 1, 1, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 2; i < MAX; i++){
            for(int j = 2; i * j < MAX; j++){
                sosu[i * j] = 1;
            }
        }
    
    while(1){
        int a;
        cin >> a;
        bool iswrong = true;
        if(a == 0)
            break;
        else{
            for(int i = 3; i < a; i += 2){
                if(sosu[i] == 0 && sosu[a - i] == 0){
                    cout << a << " = " << i << " + " << a - i << "\n";
                    iswrong = false;
                    break;
                }
            }
            if(iswrong)
                cout << "Goldbach's conjecture is wrong.";
        }
    }
    return 0;
}