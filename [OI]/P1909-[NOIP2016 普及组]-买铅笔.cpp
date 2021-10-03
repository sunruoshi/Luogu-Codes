#include <cstdio>

int main() {
    int n, ans = 0x3f3f3f3f;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        int temp[2], c;
        scanf("%d %d", &temp[0], &temp[1]);
        c = n % temp[0] == 0 ? n / temp[0] * temp[1] : (n / temp[0] + 1) * temp[1];
        ans = c < ans ? c : ans;
    }
    printf("%d", ans);
    return 0;
}
