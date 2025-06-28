#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#define INF 987654321.0
using namespace std;

int n, w;
double m;
vector<pair<int, int>> vec;
vector<pair<int, double>> graph[1000];
double dist[1000];

void dijk(){
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        double d = pq.top().first;
        int tmp = pq.top().second;
        pq.pop();
        for(int i = 0; i < graph[tmp].size(); i++){
            int nx = graph[tmp][i].first;
            double nd = graph[tmp][i].second;
            if(dist[nx] > d + nd){
                dist[nx] = d + nd;
                pq.push({d + nd, nx});
            }
        }
    }
}


int main() {
	cin >> n >> w >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vec.push_back({x, y});
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			double cost = sqrt(pow(vec[j].first - vec[i].first, 2) + pow(vec[j].second - vec[i].second, 2));
			if (cost <= m) {
				graph[i].push_back({ j, cost });
				graph[j].push_back({ i, cost });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < w; i++) {
		cin >> x >> y;
		graph[x - 1].push_back({y - 1, 0});
		graph[y - 1].push_back({x - 1, 0});
	}
	dijk();
	int result = (int)(dist[n - 1] * 1000);
	cout << result;
	return 0;
}