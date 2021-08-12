#include <cstdio>
#include <algorithm>
using namespace std;

int w[101], c[101], dp[2][1001];

int main() {
    int t, m, cur = 0;
    scanf("%d %d", &t, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &w[i], &c[i]);
    }
    for (int i = 1; i <= m; i++) {
        cur = 1 - cur;
        for (int j = 0; j <= t; j++) {
            if (w[i] <= j) dp[cur][j] = max(dp[1 - cur][j], dp[1 - cur][j - w[i]] + c[i]);
            else dp[cur][j] = dp[1 - cur][j];
        }
    }
    printf("%d", dp[cur][t]);
    return 0;
}
