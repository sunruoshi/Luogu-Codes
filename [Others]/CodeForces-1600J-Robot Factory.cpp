#include <cstdio>
#include <queue>
#define MAXN 1000
using namespace std;

const int dirs[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int n, m, g[MAXN][MAXN];
bool vis[MAXN][MAXN];
priority_queue<int> q;

void dfs(int x, int y, int& cnt) {
    cnt++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if ((1 << i) & g[x][y]) continue;
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
            dfs(nx, ny, cnt);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                int cnt = 0;
                dfs(i, j, cnt);
                q.push(cnt);
            }
        }
    }
    while (q.size()) {
        printf("%d ", q.top());
        q.pop();
    }
    return 0;
}
