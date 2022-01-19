#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 1001, DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m, cnt, ans[MAXN][MAXN];
char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
set<pair<int, int>> st;

void dfs(int x, int y) {
    if (vis[x][y]) return;
    if (g[x][y] == '*') {
        st.insert({x, y});
        return;
    }
    vis[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nx = x + DIRS[i][0], ny = y + DIRS[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            dfs(nx, ny);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || g[i][j] == '*') continue;
            cnt = 0;
            dfs(i, j);
            for (auto p : st) {
                ans[p.first][p.second] += cnt;
            }
            st.clear();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') printf(".");
            else printf("%d", (ans[i][j] + 1) % 10);
        }
        printf("\n");
    }
    return 0;
}
