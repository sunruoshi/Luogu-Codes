#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 50, MOD = 1e9 + 7, dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int m, n, maxMove, sx, sy, ans;

int main() {
    scanf("%d %d %d %d %d", &m, &n, &maxMove, &sx, &sy);
    int dp[maxMove + 1][m][n];
    memset(dp, 0, sizeof(dp));
    dp[0][sx][sy] = 1;
    for (int i = 0; i < maxMove; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (dp[i][j][k]) {
                    for (auto dir : dirs) {
                        int nj = j + dir[0], nk = k + dir[1];
                        if (nj >= 0 && nj < m && nk >= 0 && nk < n) {
                            dp[i + 1][nj][nk] += dp[i][j][k];
                            dp[i + 1][nj][nk] %= MOD;
                        } else {
                            ans += dp[i][j][k];
                            ans %= MOD;
                        }
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
