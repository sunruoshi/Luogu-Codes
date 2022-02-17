#include <iostream>
using namespace std;

const long long MAXN = 1e5, INF = 999999999999999;

long long l, k, cnt, res, x[MAXN + 1];

bool check(long long d, bool opt) {
    cnt = 0, res = 0;
    for (int i = 1; i <= l; i++) {
        cnt += x[i];
        if (cnt < 0) cnt = 0;
        if (cnt >= d) {
            res++;
            cnt = 0;
        }
    }
    return opt ? res >= k : res <= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> l >> k;
    for (int i = 1; i <= l; i++) {
        cin >> x[i];
    }
    long long L = 1, R = INF, ans = -1;
    while (L <= R) {
        long long mid = (L + R) >> 1;
        if (check(mid, 0)) {
            if (res == k) ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    if (ans == -1) {
        cout << -1;
    } else {
        cout << ans << ' ';
        L = 1, R = INF, ans = -1;
        while (L <= R) {
            long long mid = (L + R) >> 1;
            if (check(mid, 1)) {
                if (res == k) ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        cout << ans;
    }
    return 0;
}
