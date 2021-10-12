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
    int leftMax[n], rightMax[n];
    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(height[i], leftMax[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(height[i], rightMax[i + 1]);
    }
    for (int i = 1; i < n - 1; i++) {
        ans += min(leftMax[i], rightMax[i]) - height[i];
    }
    printf("%d", ans);
    return 0;
}
