#include <cstdio>

const int MAXN = 100000;

int ans, left, right, price[MAXN], time[MAXN];

int main() {
    // freopen("transfer.in", "r", stdin);
    // freopen("transfer.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int d, p, t;
        scanf("%d %d %d", &d, &p, &t);
        if (!d) {
            right = i;
            price[i] = p;
            time[i] = t;
            ans += p;
        } else {
            bool flag = 0;
            while (t - time[left] > 45) {
                left++;
            }
            for (int j = left; j <= right; j++) {
                if (price[j] && price[j] >= p) {
                    price[j] = 0;
                    flag = 1;
                    break;
                }
            }
            if (!flag) ans += p;
        }
    }
    printf("%d", ans);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
