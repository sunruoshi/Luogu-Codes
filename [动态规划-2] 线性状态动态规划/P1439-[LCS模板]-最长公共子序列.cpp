#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1;

int n, p, a[MAXN], b[MAXN], m[MAXN], f[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        m[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (m[b[i]] > f[p]) f[++p] = m[b[i]];
        else f[lower_bound(f + 1, f + p + 1, m[b[i]]) - f] = m[b[i]];
    }
    printf("%d", p);
    return 0;
}
