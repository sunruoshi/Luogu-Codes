#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 1e5 + 1;

int n, p1, p2, arr[MAXN], dp1[MAXN], dp2[MAXN];

int main() {
    while (~scanf("%d", &arr[++n]));
    dp1[++p1] = dp2[++p2] = arr[1];
    for (int i = 2; i < n; i++) {
        if (arr[i] <= dp1[p1]) dp1[++p1] = arr[i];
        else dp1[upper_bound(dp1 + 1, dp1 + p1 + 1, arr[i], greater<int>()) - dp1] = arr[i];
        if (arr[i] > dp2[p2]) dp2[++p2] = arr[i];
        else dp2[lower_bound(dp2 + 1, dp2 + p2 + 1, arr[i]) - dp2] = arr[i];
    }
    printf("%d\n%d", p1, p2);
    return 0;
}
