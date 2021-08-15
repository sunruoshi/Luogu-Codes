#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

int main() {
    char s[MAXN];
    scanf("%s", s);
    int n = strlen(s);
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    printf("%d", dp[0][n - 1]);
    return 0;
}
