#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 1, MOD = 1e8 - 3;

int n, a[MAXN], b[MAXN], c[MAXN], d[MAXN], q[MAXN], bit[MAXN];

void update(int x) {
    while (x <= n) {
        bit[x] += 1;
        x += x & (-x);
    }
}

int query(int x) {
    int res = 0;
    while (x) {
        res += bit[x];
        x -= x & (-x);
    }
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        d[i] = i;
    }
    sort(c + 1, c + n + 1, [&](int i, int j) { return a[i] < a[j]; });
    sort(d + 1, d + n + 1, [&](int i, int j) { return b[i] < b[j]; });
    for (int i = 1; i <= n; i++) {
        q[c[i]] = d[i];
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        update(q[i]);
        ans = (ans + query(q[i] - 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
