#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int l = 1, r = n;
    while (l < n && a[l] < a[l + 1]) l++;
    while (r > 1 && a[r] < a[r - 1]) r--;
    r = n - r + 1;
    if ((l & 1) || (r & 1)) printf("Alice");
    else printf("Bob");
    return 0;
}
