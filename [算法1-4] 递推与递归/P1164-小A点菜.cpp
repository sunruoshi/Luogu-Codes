#include <bits/stdc++.h>
using namespace std;

int n, m, arr[101], dp[101][10001];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == arr[i]) dp[i][j] = dp[i - 1][j] + 1;
            else if (j > arr[i]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i]];
            else if (j < arr[i]) dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}
