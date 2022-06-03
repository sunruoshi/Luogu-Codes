#include <iostream>
#include <algorithm>

#define ll long long
#define lc cur << 1
#define rc (cur << 1) + 1

const int MAXN = 2e5 + 1;

int v[MAXN];

struct L {
    int x, y1, y2, d;
    bool operator < (const L &a) const {
        return x < a.x;
    }
} line[MAXN];

struct segment_tree {
    int l, r, cover;
    ll len;
} st[MAXN << 3];

inline void push_up(int cur) {
    st[cur].len = st[cur].cover ? st[cur].r - st[cur].l : st[lc].len + st[rc].len;
}

void build(int l, int r, int cur = 1) {
    st[cur].l = v[l];
    st[cur].r = v[r];
    if (r - l <= 1) return;
    int mid = (l + r) >> 1;
    build(l, mid, lc);
    build(mid, r, rc);
}

void update(int l, int r, int d, int cur = 1) {
    if (l <= st[cur].l && st[cur].r <= r) {
        st[cur].cover += d;
        push_up(cur);
        return;
    }
    if (l < st[lc].r) update(l, r, d, lc);
    if (r > st[rc].l) update(l, r, d, rc);
    push_up(cur);
}

int main() {
    using namespace std;
    int n, x1, y1, x2, y2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        x1 = a, y1 = d, x2 = c, y2 = b;
        v[i] = y1;
        v[i + n] = y2;
        line[i] = L({x1, y1, y2, 1});
        line[i + n] = L({x2, y1, y2, -1});
    }
    sort(v + 1, v + (n << 1) + 1);
    sort(line + 1, line + (n << 1) + 1);
    build(1, n << 1);
    ll ans = 0;
    for (int i = 1; i <= n << 1; i++) {
        ans += st[1].len * (line[i].x - line[i - 1].x);
        update(line[i].y1, line[i].y2, line[i].d);
    }
    cout << ans << endl;
    return 0;
}
