#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f, dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Node {
    int x, y, w;
    Node(int _x, int _y, int _w) : x(_x), y(_y), w(_w) {}
    bool operator < (const Node &a) const {
        return w > a.w;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int heights[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &heights[i][j]);
        }
    }
    bool visited[n * m];
    int dis[n * m];
    memset(visited, 0, sizeof(visited));
    fill(dis, dis + n * m, INF);
    dis[0] = 0;
    priority_queue<Node> q;
    q.push(Node(0, 0, 0));
    while (q.size()) {
        int x = q.top().x, y = q.top().y, w = q.top().w;
        q.pop();
        if (visited[m * x + y]) continue;
        visited[m * x + y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            int d = max(abs(heights[x][y] - heights[nx][ny]), w);
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && d < dis[m * nx + ny]) {
                dis[m * nx + ny] = d;
                q.push(Node(nx, ny, d));
            }
        }
    }
    printf("%d", dis[n * m - 1]);
    return 0;
}
