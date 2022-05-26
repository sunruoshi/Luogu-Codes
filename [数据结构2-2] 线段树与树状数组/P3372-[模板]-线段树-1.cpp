#include <iostream>

#define ll long long
#define lc cur << 1
#define rc (cur << 1) + 1
#define mid ((s + t) >> 1)

const int N = 1e5 + 1;

int n, m, a[N];
ll d[N << 2], tag[N << 2];


inline void push_up(int cur) {
    d[cur] = d[lc] + d[rc];
}

inline void push_down(int s, int t, int cur = 1) {
    d[lc] += tag[cur] * (mid - s + 1);
    d[rc] += tag[cur] * (t - mid);
    tag[lc] += tag[cur];
    tag[rc] += tag[cur];
    tag[cur] = 0;
}

void build(int s, int t, int cur = 1) {
    if (s == t) {
        d[cur] = a[s];
        return;
    }
    build(s, mid, lc);
    build(mid + 1, t, rc);
    push_up(cur);
}

void update(int l, int r, ll v, int s = 1, int t = n, int cur = 1) {
    if (l <= s && t <= r) {
        d[cur] += (t - s + 1) * v;
        tag[cur] += v;
        return;
    }
    if (s < t && tag[cur]) push_down(s, t, cur);
    if (l <= mid) update(l, r, v, s, mid, lc);
    if (r > mid) update(l, r, v, mid + 1, t, rc);
    push_up(cur);
}

ll query(int l, int r, int s = 1, int t = n, int cur = 1) {
    if (l <= s && t <= r) return d[cur];
    if (s < t && tag[cur]) push_down(s, t, cur);
    ll res = 0;
    if (l <= mid) res = query(l, r, s, mid, lc);
    if (r > mid) res += query(l, r, mid + 1, t, rc);
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
