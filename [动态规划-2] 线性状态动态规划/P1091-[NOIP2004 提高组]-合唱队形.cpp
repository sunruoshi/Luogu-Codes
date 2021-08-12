#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 101;

int n, ans, p1, p2, arr[MAXN], dp1[MAXN], dp2[MAXN], f1[MAXN], f2[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] > f1[p1]) f1[++p1] = arr[i];
        else f1[lower_bound(f1 + 1, f1 + p1 + 1, arr[i]) - f1] = arr[i];
        dp1[i] = p1;
    }
    for (int i = n; i >= 1; i--) {
        if (arr[i] > f2[p2]) f2[++p2] = arr[i];
        else f2[lower_bound(f2 + 1, f2 + p2 + 1, arr[i]) - f2] = arr[i];
        dp2[i] = p2;
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    printf("%d", n - ans);
    return 0;
}
