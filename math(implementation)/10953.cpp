#include <iostream>
using namespace std;

int main() {
    int t;
    char trash;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> trash >> b;
        cout << a + b << endl;
    }
    return 0;
}