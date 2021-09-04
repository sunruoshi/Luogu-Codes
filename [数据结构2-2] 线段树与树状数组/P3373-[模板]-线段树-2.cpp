#include <cstdio>
#include <vector>
using namespace std;

struct Node {
    long long val, mul, add;
};

class SegmentTree {
    private:
        vector<Node> d;
        int MOD;
        void build(int s, int t, int root, vector<long long> &a) {
            d[root].mul = 1;
            d[root].add = 0;
            if (s == t) {
                d[root].val = a[s];
                return;
            }
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            build(s, m, left, a);
            build(m + 1, t, right, a);
            d[root].val = (d[left].val + d[right].val) % MOD;
        }
        void pushDown(int s, int t, int root) {
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            d[left].val = (d[left].val * d[root].mul + d[root].add * (m - s + 1)) % MOD;
            d[right].val = (d[right].val * d[root].mul + d[root].add * (t - m)) % MOD;
            d[left].mul = (d[left].mul * d[root].mul) % MOD;
            d[right].mul = (d[right].mul * d[root].mul) % MOD;
            d[left].add = (d[left].add * d[root].mul + d[root].add) % MOD;
            d[right].add = (d[right].add * d[root].mul + d[root].add) % MOD;
            d[root].mul = 1;
            d[root].add = 0;
        }
    public:
        SegmentTree(int n, int p, vector<long long> &a) {
            d.resize(n * 3);
            MOD = p;
            build(1, n, 1, a);
        }
        void update_mul(int l, int r, long long v, int s, int t, int root) {
            if (l <= s && t <= r) {
                d[root].val = (d[root].val * v) % MOD;
                d[root].mul = (d[root].mul * v) % MOD;
                d[root].add = (d[root].add * v) % MOD;
                return;
            }
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            if (s != t) pushDown(s, t, root);
            if (l <= m) update_mul(l, r, v, s, m, left);
            if (r > m) update_mul(l, r, v, m + 1, t, right);
            d[root].val = (d[left].val + d[right].val) % MOD;
        }
        void update_add(int l, int r, long long v, int s, int t, int root) {
            if (l <= s && t <= r) {
                d[root].val = (d[root].val + v * (t - s + 1)) % MOD;
                d[root].add = (d[root].add + v) % MOD;
                return;
            }
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            if (s != t) pushDown(s, t, root);
            if (l <= m) update_add(l, r, v, s, m, left);
            if (r > m) update_add(l, r, v, m + 1, t, right);
            d[root].val = (d[left].val + d[right].val) % MOD;
        }
        long long query(int l, int r, int s, int t, int root) {
            if (l <= s && t <= r) return d[root].val;
            int m = s + ((t - s) >> 1), left = root * 2, right = root * 2 + 1;
            if (s != t) pushDown(s, t, root);
            long long res = 0;
            if (l <= m) res = (res + query(l, r, s, m, left)) % MOD;
            if (r > m) res  = (res + query(l, r, m + 1, t, right)) % MOD;
            return res;
        }
};

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    SegmentTree st(n, p, a);
    while (m--) {
        int opt, x, y;
        long long k;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) {
            scanf("%lld", &k);
            st.update_mul(x, y, k, 1, n, 1);
        } else if (opt == 2) {
            scanf("%lld", &k);
            st.update_add(x, y, k, 1, n, 1);
        } else {
            printf("%lld\n", st.query(x, y, 1, n, 1));
        }
    }
    return 0;
}
