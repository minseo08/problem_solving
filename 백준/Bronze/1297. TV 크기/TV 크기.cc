#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int l, h, w;
    cin >> l >> h >> w;
    cout << (int)(l / sqrt(h * h + w * w) * h) << " " << (int)(l / sqrt(h * h + w * w) * w) << "\n";

    return 0;
}