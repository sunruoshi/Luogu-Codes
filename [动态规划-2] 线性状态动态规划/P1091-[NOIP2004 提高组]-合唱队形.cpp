#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 101;

int n, ans, arr[MAXN], dp1[MAXN], dp2[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++) {
        dp1[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        dp2[i] = 1;
        for (int j = n; j > i; j--) {
            if (arr[i] > arr[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    printf("%d", n - ans);
    return 0;
}
