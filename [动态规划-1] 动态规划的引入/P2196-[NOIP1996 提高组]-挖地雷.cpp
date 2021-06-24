#include <cstdio>

int n, start, ans, arr[21], mat[21][21], prev[21], dp[21];

void print(int x) {
    if (prev[x] == 0) {
        printf("%d ", x);
        return;
    }
    print(prev[x]);
    printf("%d ", x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[j][i] && dp[j] > dp[i]) {
                dp[i] = dp[j];
                prev[i] = j;
            }
        }
        dp[i] += arr[i];
        if (dp[i] > ans) {
            ans = dp[i];
            start = i;
        }
    }
    print(start);
    printf("\n%d", ans);
    return 0;
}
