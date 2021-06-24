#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n, m, cnt = 0, sx, sy, dirs[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    scanf("%d %d %d %d", &n, &m, &sx, &sy);
    int board[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            board[i][j] = -1;
        }
    }
    deque<vector<int> > q;
    q.push_back({sx, sy});
    board[sx][sy] = cnt++;
    while (q.size()) {
        deque<vector<int> > cur;
        while (q.size()) {
            cur.push_back(q.front());
            q.pop_front();
        }
        while (cur.size()) {
            vector<int> pos = cur.front();
            for (int i = 0; i < 8; i++) {
                int nx = pos[0] + dirs[i][0], ny = pos[1] + dirs[i][1];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && board[nx][ny] == -1) {
                    q.push_back({nx, ny});
                    board[nx][ny] = cnt;
                }
            }
            cur.pop_front();
        }
        cnt++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", board[i][j]);
        }
        if (i != n) printf("\n");
    }
    return 0;
}
