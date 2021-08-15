#include <cstdio>

int main() {
    int n, maxn = -1e5, minn = 1e5, left = -1, right = -1;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < n; i++) {
        if (maxn > nums[i]) right = i;
        else maxn = nums[i];
        if (minn < nums[n - i - 1]) left = n - i - 1;
        else minn = nums[n - i - 1];
    }
    if (right == -1) printf("0");
    else printf("%d", right - left + 1);
    return 0;
}
