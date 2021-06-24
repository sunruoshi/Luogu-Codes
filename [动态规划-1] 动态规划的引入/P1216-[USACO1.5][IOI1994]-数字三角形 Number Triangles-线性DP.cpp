#include <cstdio>
#include <algorithm>
using namespace std;

int f[1001][1001], dp[1001][1001];

int main() {
    int r;
    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int j = 1; j <= r; j++) {
        dp[r][j] = f[r][j];
    }
    for (int i = r - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + f[i][j];
        }
    }
    printf("%d", dp[1][1]);
    return 0;
}
