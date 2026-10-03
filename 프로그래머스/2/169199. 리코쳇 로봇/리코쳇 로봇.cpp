#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dist[105][105];

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();
    int sx = 0, sy = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                sx = i;
                sy = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 1; // 거리 1부터 시작 (방문 체크 겸용)

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 목표 지점에 멈춘 경우
        if (board[cx][cy] == 'G') {
            return dist[cx][cy] - 1;
        }

        // 4방향으로 미끄러지기
        for (int i = 0; i < 4; i++) {
            int nx = cx;
            int ny = cy;

            // 벽('D')을 만나거나 맵 끝에 도달하기 직전까지 계속 직진
            while(1){
                int next_x = nx + dx[i];
                int next_y = ny + dy[i];

                if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) break;
                if (board[next_x][next_y] == 'D') break;

                nx = next_x;
                ny = next_y;
            }

            // 멈춘 위치(nx, ny)를 아직 방문하지 않았다면 큐에 삽입
            if (dist[nx][ny] == 0) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 도달할 수 없는 경우
    return -1;
}