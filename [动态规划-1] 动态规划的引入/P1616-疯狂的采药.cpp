#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    long long w[m], c[m], dp[t + 1];
    for (int i = 0; i < m; i++) {
        scanf("%ld %ld", &w[i], &c[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= t; j++) {
            if (w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    printf("%ld", dp[t]);
    return 0;
}
