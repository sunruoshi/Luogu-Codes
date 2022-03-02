#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 252, INF = 0x3f3f3f3f;

struct Edge {
    int u, v;
    Edge(int a, int b) : u(a), v(b) {}
};

int n, m, t, p;
int id[N][N], dis[N << 3][N << 3], f[N][N][4];
bool a[N][N];

bool check(int x, int y) {
    return a[x - 1][y] || a[x + 1][y] || a[x][y - 1] || a[x][y + 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        a[0][i] = a[n + 1][i] = a[i][0] = a[i][n + 1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j] && check(i, j)) id[i][j] = ++p;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j][0] = a[i][j - 1] ? id[i][j] : f[i][j - 1][0];
            f[i][j][1] = a[i - 1][j] ? id[i][j] : f[i - 1][j][1];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            f[i][j][2] = a[i][j + 1] ? id[i][j] : f[i][j + 1][2];
            f[i][j][3] = a[i + 1][j] ? id[i][j] : f[i + 1][j][3];
        }
    }
    vector<int> g[p + 1][4];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!id[i][j]) continue; 
            for (int k = 0; k < 4; k++) {
                g[f[i][j][k]][k].push_back(id[i][j]);
            }
        }
    }
    queue<Edge> q;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= p; i++) {
        q.push(Edge(i, i));
        dis[i][i] = 1;
    }
    while (q.size()) {
        Edge cur = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            for (int u : g[cur.u][k]) {
                for (int v : g[cur.v][k]) {
                    if (dis[u][v] == INF) {
                        dis[u][v] = dis[cur.u][cur.v] + 1;
                        q.push(Edge(u, v));
                    }
                }
            }
        }
    }
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && y1 == y2) {
            cout << 0 << endl;
        } else {
            int ans = INF;
            for (int k = 0; k < 4; k++) {
                ans = min(ans, dis[f[x1][y1][k]][f[x2][y2][k]]);
            }
            cout << (ans == INF ? -1 : ans) << endl;
        }
    }
    return 0;
}
