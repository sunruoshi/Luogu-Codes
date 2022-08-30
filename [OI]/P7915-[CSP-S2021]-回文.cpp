#include <cstdio>
#include <cstring>

const int N = 1e6 + 1;

int t, n, a[N];
char s[N];

bool solve(int l1, int r1, int l2, int r2) {
    for (int i = 1; i < n; i++) {
        if (l1 <= r1 && ((l2 <= r2 && a[l1] == a[l2]) || (l1 < r1 && a[l1] == a[r1]))) {
            if (l1 < r1 && a[l1] == a[r1]) {
                s[i] = s[2 * (n - 1) - i + 1] = 'L';
                l1++;
                r1--;
            } else {
                s[i] = 'L';
                s[2 * (n - 1) - i + 1] = 'R';
                l1++;
                l2++;
            }
        } else if (l2 <= r2 && ((l1 <= r1 && a[r2] == a[r1]) || (l2 < r2 && a[l2] == a[r2]))){
            if (l2 < r2 && a[l2] == a[r2]) {
                s[i] = s[2 * (n - 1) - i + 1] = 'R';
                l2++;
                r2--;
            } else {
                s[i] = 'R';
                s[2 * (n - 1) - i + 1] = 'L';
                r1--;
                r2--;
            }
        } else {
            return 0;
        }
    }
    return 1; 
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", a + i);
        }
        memset(s, 0, sizeof(s));
        int p1, p2;
        for (p1 = 2; p1 <= 2 * n; p1++) {
            if (a[p1] == a[1]) break;
        }
        for (p2 = 1; p2 < 2 * n; p2++) {
            if (a[p2] == a[2 * n]) break;
        }
        if (solve(2, p1 - 1, p1 + 1, 2 * n)) printf("L%sL\n", s + 1);
        else if (solve(1, p2 - 1, p2 + 1, 2 * n - 1)) printf("R%sL\n", s + 1);
        else printf("-1\n");
    }
    return 0;
}
