#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1000, DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m, p[MAXN][MAXN];
bool flag, vis[MAXN][MAXN];

void dfs(int x, int y, int cost) {
    if (flag) return;
    if (x == n - 1) {
        flag = 1;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + DIRS[i][0], ny = y + DIRS[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && p[nx][ny] <= cost) {
            dfs(nx, ny, cost);
        }
    }
}

bool check(int x) {
    for (int i = 0; i < m; i++) {
        if (p[1][i] > x) continue;
        dfs(1, i, x);
        if (flag) break;
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p[i][j];
        }
    }
    int l = 0, r = 1000, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        memset(vis, 0, sizeof(vis));
        flag = 0;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
