#include <cstdio>

int main() {
    int n, res[7], ans[7] = {0, 0, 0, 0, 0, 0, 0};
    scanf("%d\n%d %d %d %d %d %d %d", &n, &res[0], &res[1], &res[2], &res[3], &res[4], &res[5], &res[6]);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0, d = 0; j < 7; ++j) {
            scanf("%d", &d);
            for (int k = 0; k < 7; ++k) {
                if (res[k] == d) {
                    cnt++;
                    break;
                }
            }
        }
        if (cnt > 0) ans[cnt - 1]++;
    }
    for (int i = 6; i >= 0; i--) printf("%d ", ans[i]);
    return 0;
}
