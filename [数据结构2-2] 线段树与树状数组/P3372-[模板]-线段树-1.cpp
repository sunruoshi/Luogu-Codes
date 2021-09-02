#include <cstdio>
#include <vector>
using namespace std;

struct SegmentTree {
    vector<long long> d, mark;
    SegmentTree(int n) {
        d.resize(n * 3);
        mark.resize(n * 3);
    }
    void build(int s, int t, int root, vector<long long> &a) {
        if (s == t) {
            d[root] = a[s];
            return;
        }
        int m = s + ((t - s) >> 1);
        build(s, m, root * 2, a);
        build(m + 1, t, root * 2 + 1, a);
        d[root] = d[root * 2] + d[root * 2 + 1];
    }
    void pushDown(int s, int t, int root) {
        int m = s + ((t - s) >> 1);
        d[root * 2] += mark[root] * (m - s + 1);
        d[root * 2 + 1] += mark[root] * (t - m);
        mark[root * 2] += mark[root];
        mark[root * 2 + 1] += mark[root];
        mark[root] = 0;
    }
    long long query(int l, int r, int s, int t, int root) {
        if (l <= s && t <= r) return d[root];
        int m = s + ((t - s) >> 1);
        if (mark[root]) pushDown(s, t, root);
        long long res = 0;
        if (l <= m) res += query(l, r, s, m, root * 2);
        if (r > m) res += query(l, r, m + 1, t, root * 2 + 1);
        return res;
    }
    void update(int l, int r, int c, int s, int t, int root) {
        if (l <= s && t <= r) {
            d[root] += (t - s + 1) * c;
            mark[root] += c;
            return;
        }
        int m = s + ((t - s) >> 1);
        if (mark[root] && s != t) pushDown(s, t, root);
        if (l <= m) update(l, r, c, s, m, root * 2);
        if (r > m) update(l, r, c, m + 1, t, root * 2 + 1);
        d[root] = d[root * 2] + d[root * 2 + 1];
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    SegmentTree st(n + 1);
    st.build(1, n, 1, a);
    while (m--) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int x, y, k;
            scanf("%d %d %d", &x, &y, &k);
            st.update(x, y, k, 1, n, 1);
        } else {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%lld\n", st.query(x, y, 1, n, 1));
        }
    }
    return 0;
}
