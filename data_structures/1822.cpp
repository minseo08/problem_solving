#include <iostream>
#include <set>
using namespace std;
set<int> s;

int main(){
    int a, b;
    int x;
    int y;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> x;
        s.insert(x);
    }
    for(int i = 0; i < b; i++){
        cin >> y;
        s.erase(y);
    }
    cout << s.size() << "\n";
    for(set<int>::iterator i = s.begin(); i != s.end(); i++){
        cout << *i << " ";
    }
    return 0;
}