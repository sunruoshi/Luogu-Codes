#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 101
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int w[n + 1], g[n + 1][n + 1];
    memset(w, 0, sizeof(w));
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
        int left, right;
        scanf("%d %d %d", &w[i], &left, &right);
        if (left) g[i][left] = g[left][i] = 1;
        if (right) g[i][right] = g[right][i] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] == INF || g[k][j] == INF) continue;
                if (g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += g[i][j] * w[j];
        }
        ans = min(ans, sum);
    }
    printf("%d", ans);
    return 0;
}
