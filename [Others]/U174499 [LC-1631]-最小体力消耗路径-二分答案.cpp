#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;

struct Node {
    int x, y;
    Node(int _x, int _y) : x(_x), y(_y) {}
};

int main() {
    int n, m, ans = 0, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    scanf("%d %d", &n, &m);
    int heights[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &heights[i][j]);
        }
    }
    int left = 0, right = 1e6 - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        deque<Node> q;
        q.push_back(Node(0, 0));
        bool visited[n * m];
        memset(visited, 0, sizeof(visited));
        visited[0] = 1;
        while (q.size()) {
            int x = q.front().x, y = q.front().y;
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[m * nx + ny] && abs(heights[x][y] - heights[nx][ny]) <= mid) {
                    q.push_back(Node(nx, ny));
                    visited[m * nx + ny] = 1;
                }
            }
        }
        if (visited[n * m - 1]) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}
