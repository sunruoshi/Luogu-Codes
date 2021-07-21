#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans = 1e9, s[11], b[11];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &s[i], &b[i]);
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int ts = 1, tb = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                ts *= s[i + 1];
                tb += b[i + 1];
                ans = min(ans, abs(ts - tb));
            }
        }
    }
    printf("%d", ans);
    return 0;
}
