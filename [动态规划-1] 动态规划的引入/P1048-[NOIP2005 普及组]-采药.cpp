#include <cstdio>
#include <algorithm>
using namespace std;

int w[100], c[100], dp[1001];

int main() {
    int t, m;
    scanf("%d %d", &t, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &w[i], &c[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = t; j >= 1; j--) {
            if (w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    printf("%d", dp[t]);
    return 0;
}
