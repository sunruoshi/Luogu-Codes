#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int r, f[1001][1001], dp[1001][1001];

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x != r) dp[x][y] = f[x][y] + max(dfs(x + 1, y), dfs(x + 1, y + 1));
    else dp[x][y] = f[x][y];
    return dp[x][y];
}

int main() {
    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", dfs(1, 1));
    return 0;
}
