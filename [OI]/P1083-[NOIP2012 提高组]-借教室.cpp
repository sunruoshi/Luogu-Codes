#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e6 + 2;

int n, m, r[MAXN], d[MAXN], s[MAXN], t[MAXN], diff[MAXN];

bool check(int x) {
    memset(diff, 0, sizeof(diff));
    for (int i = 1; i <= x; i++) {
        diff[s[i]] -= d[i];
        diff[t[i] + 1] += d[i];
    }
    int tag = 0, flag = 1;
    for (int i = 1; i <= n; i++) {
        tag += diff[i];
        if (r[i] + tag < 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> d[i] >> s[i] >> t[i];
    }
    int l = 1, r = m, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (ans == m) cout << 0;
    else cout << -1 << endl << ans + 1;
    return 0;
}
