#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

struct Node {
    int x, y;
    Node(int _x, int _y) : x(_x), y(_y) {}
};

int main() {
    int n, m, ans = 0, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    scanf("%d %d", &n, &m);
    int h[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &h[i][j]);
        }
    }
    int l = 0, r = 1e6 - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        queue<Node> q;
        q.push(Node(0, 0));
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        vis[0][0] = 1;
        while (q.size()) {
            int x = q.front().x, y = q.front().y;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx < 0 || nx == n || ny < 0 || ny == m) continue;
                if (!vis[nx][ny] && abs(h[x][y] - h[nx][ny]) <= mid) {
                    q.push(Node(nx, ny));
                    vis[nx][ny] = 1;
                }
            }
        }
        if (vis[n - 1][m - 1]) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}
