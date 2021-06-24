// P1048 采药 二维DP数组解法
#include <cstdio>
#include <algorithm>
using namespace std;

int w[101], c[101], dp[101][1001];

int main() {
    int t, m; // t为背包容量
    scanf("%d %d", &t, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &w[i], &c[i]); // 读入每种草药采摘需要的时间和草药的价值
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= t; j++) {
            // 状态转移方程
            if (w[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[m][t]); // dp[m][t]即为答案
    return 0;
}
