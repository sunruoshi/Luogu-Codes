#include <iostream>
using namespace std;

const int MAXN = 5e4 + 1, INF = 0x3f3f3f3f;

#define lc cur << 1
#define rc (cur << 1) + 1
#define mid ((d[cur].l + d[cur].r) >> 1)

struct segment_tree {
    int l, r, MAX, MIN;
} d[MAXN << 2];

int n, q, a[MAXN];

inline void push_up(int cur) {
    d[cur].MAX = max(d[lc].MAX, d[rc].MAX);
    d[cur].MIN = min(d[lc].MIN, d[rc].MIN);
}

void build(int l, int r, int cur = 1) {
    d[cur].l = l;
    d[cur].r = r;
    if (l == r) {
        d[cur].MAX = d[cur].MIN = a[l];
        return;
    }
    build(l, mid, lc);
    build(mid + 1, r, rc);
    push_up(cur);
}

int query_max(int l, int r, int cur = 1) {
    if (l <= d[cur].l && d[cur].r <= r) return d[cur].MAX;
    int res = -INF;
    if (l <= mid) res = max(res, query_max(l, r, lc));
    if (r > mid) res = max(res, query_max(l, r, rc));
    return res;
}

int query_min(int l, int r, int cur = 1) {
    if (l <= d[cur].l && d[cur].r <= r) return d[cur].MIN;
    int res = INF;
    if (l <= mid) res = min(res, query_min(l, r, lc));
    if (r > mid) res = min(res, query_min(l, r, rc));
    return res;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query_max(l, r) - query_min(l, r) << endl;
    }
    return 0;
}
