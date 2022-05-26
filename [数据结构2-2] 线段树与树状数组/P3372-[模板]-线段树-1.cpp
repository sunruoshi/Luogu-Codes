#include <iostream>

#define ll long long
#define lc cur << 1
#define rc (cur << 1) + 1
#define mid ((d[cur].l + d[cur].r) >> 1)

const int N = 1e5 + 1;

struct segmment_tree {
    int l, r;
    ll w, t;
} d[N << 2];

int n, m, a[N];

inline void push_up(int cur) {
    d[cur].w = d[lc].w + d[rc].w;
}

inline void push_down(int cur) {
    d[lc].w += d[cur].t * (mid - d[cur].l + 1);
    d[rc].w += d[cur].t * (d[cur].r - mid);
    d[lc].t += d[cur].t;
    d[rc].t += d[cur].t;
    d[cur].t = 0;
}

void build(int l, int r, int cur = 1) {
    d[cur].l = l;
    d[cur].r = r;
    d[cur].t = 0;
    if (l == r) {
        d[cur].w = a[l];
        return;
    }
    build(l, mid, lc);
    build(mid + 1, r, rc);
    push_up(cur);
}

void update(int l, int r, ll v, int cur = 1) {
    if (l <= d[cur].l && d[cur].r <= r) {
        d[cur].w += (d[cur].r - d[cur].l + 1) * v;
        d[cur].t += v;
        return;
    }
    if (d[cur].l < d[cur].r && d[cur].t) push_down(cur);
    if (l <= mid) update(l, r, v, lc);
    if (r > mid) update(l, r, v, rc);
    push_up(cur);
}

ll query(int l, int r, int cur = 1) {
    if (l <= d[cur].l && d[cur].r <= r) return d[cur].w;
    if (d[cur].l < d[cur].r && d[cur].t) push_down(cur);
    ll res = 0;
    if (l <= mid) res += query(l, r, lc);
    if (r > mid) res += query(l, r, rc);
    return res;
}

int main() {
    std::cin.sync_with_stdio(0);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    build(1, n);
    while (m--) {
        int opt, x, y, k;
        std::cin >> opt >> x >> y;
        if (opt == 1) {
            std::cin >> k;
            update(x, y, k);
        } else {
            std::cout << query(x, y) << '\n';
        }
    }
    return 0;
}
