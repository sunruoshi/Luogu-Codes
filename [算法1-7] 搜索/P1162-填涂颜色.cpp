#include <cstdio>
#include <deque>
using namespace std;

int n, mat[30][30], dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node {
    int x, y;
    Node(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

void bfs(Node s) {
    deque<Node> q;
    q.push_back(s);
    while (q.size()) {
        Node cur = q.front();
        q.pop_front();
        mat[cur.x][cur.y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dirs[i][0], ny = cur.y + dirs[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && mat[nx][ny] == 2) {
                q.push_back(Node(nx, ny));
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 0) mat[i][j] = 2;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 || i == n - 1 || j == 0 || j == n - 1) && mat[i][j] == 2) {
                bfs(Node(i, j));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
