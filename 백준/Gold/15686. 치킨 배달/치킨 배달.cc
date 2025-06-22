#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define INF 987654321
struct House {
    int r, c;
};
struct Chicken {
    int r, c;
    bool visited;
};
int n, m;
int min_cd = INF;
vector<House> house;
vector<Chicken> chicken;

void Cal() {
    int cd = 0;
    for (int i=0; i<house.size(); i++) {
        int min_hd = INF;
        for (int j=0; j<chicken.size(); j++) {
            if (chicken[j].visited) {
                int hd = abs(house[i].r - chicken[j].r) + abs(house[i].c - chicken[j].c);
                if (hd < min_hd) {
                    min_hd = hd;
                }
            }
        }
        cd += min_hd;
    }
    if (cd < min_cd) {
        min_cd = cd;
    }
}

void dfs(int index, int count) {
    if (count == m) {
        Cal();
    }
    for (int i = index; i < chicken.size(); i++) {
        if (!chicken[i].visited) {
            chicken[i].visited = true;
            dfs(i, count + 1);
            chicken[i].visited = false;
        }
    }
}

int main() {
    cin >> n >> m;

    int flag;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> flag;
            if (flag == 1) { house.push_back({i, j}); }
            else if (flag == 2) { chicken.push_back({i, j, false}); }
        }
    }
    dfs(0, 0);
    cout << min_cd;

    return 0;
}