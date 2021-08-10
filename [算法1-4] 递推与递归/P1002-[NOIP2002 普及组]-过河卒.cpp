#include <cstdio>
#include <algorithm>
using namespace std;

int ban[22][22];
long long dp[22][22];

int main() {
    int n, m, hx, hy, dirs[9][2] = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    scanf("%d %d %d %d", &n, &m, &hx, &hy);
    for (int i = 0; i < 9; i++) {
        int dx = hx + 1 + dirs[i][0], dy = hy + 1 + dirs[i][1];
        if (dx >= 1 && dx <= n + 1 && dy >= 1 && dy <= m + 1) ban[dx][dy]++;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            if (!ban[i][j]) dp[i][j] = max(dp[i][j], dp[i - 1][j] + dp[i][j - 1]);
        }
    }
    printf("%lld", dp[n + 1][m + 1]);
    return 0;
}
