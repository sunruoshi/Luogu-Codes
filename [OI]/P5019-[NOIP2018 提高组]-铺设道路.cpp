#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[i - 1]) ans += arr[i] - arr[i - 1];
    }
    printf("%d", ans);
    return 0;
}
