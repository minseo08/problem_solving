#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc_dist(int x, int y, int a, int b) {
    return ((x - a) * (x - a)) + ((b - y) * (b - y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w, h, x, y, p, cnt = 0;
    cin >> w >> h >> x >> y >> p;
    for(int t = 0; t < p; t++){
        int a, b;
        int r= (h / 2) * (h / 2);
        cin >> a >> b;
        if(x <= a && a <= x + w && y <= b && b <= y + h)
            cnt++;
        else if(((x - a) * (x - a) + (y + h / 2 - b) * (y + h / 2 - b)) <= r)
            cnt++;
        else if(((x + w - a) * (x + w - a) + (y + h / 2 - b) * (y + h / 2 - b)) <= r)
            cnt++;
    }
    cout << cnt << "\n";

    return 0;
}