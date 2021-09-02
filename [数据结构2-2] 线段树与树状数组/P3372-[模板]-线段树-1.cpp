#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    long long val, tag;
    Node() {}
    Node(long long v, long long t) : val(v), tag(t) {}
};

class SegmentTree {
    private:
        vector<Node> d;
        void build(int s, int t, int root, vector<long long> &a) {
            if (s == t) {
                d[root] = Node(a[s], 0);
                return;
            }
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            build(s, m, left, a);
            build(m + 1, t, right, a);
            d[root].val = d[left].val + d[right].val;
        }
        void pushDown(int s, int t, int root) {
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            d[left].val += d[root].tag * (m - s + 1);
            d[right].val += d[root].tag * (t - m);
            d[left].tag += d[root].tag;
            d[right].tag += d[root].tag;
            d[root].tag = 0;
        }

    public:
        SegmentTree(int n, vector<long long> &a) {
            d.resize(n * 3);
            build(1, n, 1, a);
        }
        void update(int l, int r, int v, int s, int t, int root) {
            if (l <= s && t <= r) {
                d[root].val += (t - s + 1) * v;
                d[root].tag += v;
                return;
            }
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            if (d[root].tag && s != t) pushDown(s, t, root);
            if (l <= m) update(l, r, v, s, m, left);
            if (r > m) update(l, r, v, m + 1, t, right);
            d[root].val = d[left].val + d[right].val;
        }
        long long query(int l, int r, int s, int t, int root) {
            if (l <= s && t <= r) return d[root].val;
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            if (d[root].tag && s != t) pushDown(s, t, root);
            long long res = 0;
            if (l <= m) res += query(l, r, s, m, left);
            if (r > m) res += query(l, r, m + 1, t, right);
            return res;
        }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    SegmentTree st(n, a);
    while (m--) {
        int opt, x, y, k;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) {
            scanf("%d", &k);
            st.update(x, y, k, 1, n, 1);
        } else {
            printf("%lld\n", st.query(x, y, 1, n, 1));
        }
    }
    return 0;
}
