#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    int height[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }
    int left_max[n], right_max[n];
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < n - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    printf("%d", ans);
    return 0;
}
