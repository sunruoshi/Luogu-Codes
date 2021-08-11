#include <cstdio>
#include <algorithm>
using namespace std;

int r, c, ans, m[100][100], dp[100][100], dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int DP(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && m[nx][ny] < m[x][y]) {
            dp[x][y] = max(dp[x][y], DP(nx, ny) + 1);
        }
    }
    return dp[x][y];
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans = max(ans, DP(i, j));
        }
    }
    printf("%d", ans);
    return 0;
}
