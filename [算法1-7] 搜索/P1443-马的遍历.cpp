#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int n, m, dirs[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

struct Node {
    int x, y, step;
    Node(int _x, int _y, int _step) {
        x = _x;
        y = _y;
        step = _step;
    }
} s(0, 0, 0);

int main() {
    scanf("%d %d %d %d", &n, &m, &s.x, &s.y);
    int board[n + 1][m + 1];
    memset(board, -1, sizeof(board));
    deque<Node> q;
    q.push_back(s);
    board[s.x][s.y] = 0;
    while (q.size()) {
        Node cur = q.front();
        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dirs[i][0], ny = cur.y + dirs[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && board[nx][ny] == -1) {
                board[nx][ny] = cur.step + 1;
                q.push_back(Node(nx, ny, board[nx][ny]));
            }
        }
        q.pop_front();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
