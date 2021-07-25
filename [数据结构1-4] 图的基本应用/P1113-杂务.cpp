#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10001;

int n, ans, w[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u, len, temp = 0;
        scanf("%d %d", &u, &len);
        while (true) {
            int pre;
            scanf("%d", &pre);
            if (!pre) break;
            temp = max(temp, w[pre]);
        }
        w[u] = temp + len;
        ans = max(ans, w[u]);
    }
    printf("%d", ans);
    return 0;
}
