#include <cstdio>
#include <algorithm>
using namespace std;

const long long INF = 0x3f3f3f3f;

long long n, m, board[1000][1000], dp[1000][1000][2];

long long dfs(int x, int y, int dir) {
    if (x < 0 || x >= n || y < 0 || y >= m) return -INF;
    if (dp[x][y][dir] != -INF) return dp[x][y][dir];
    if (dir) dp[x][y][dir] = max(dfs(x - 1, y, 1), max(dfs(x, y - 1, 0), dfs(x, y - 1, 1))) + board[x][y];
    else dp[x][y][dir] = max(dfs(x + 1, y, 0), max(dfs(x, y - 1, 0), dfs(x, y - 1, 1))) + board[x][y];
    return dp[x][y][dir];
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &board[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                if (i == 0 && j == 0) dp[i][j][k] = board[0][0];
                else dp[i][j][k] = -INF;
            }
        }
    }
    printf("%lld", dfs(n - 1, m - 1, 1));
    return 0;
}
