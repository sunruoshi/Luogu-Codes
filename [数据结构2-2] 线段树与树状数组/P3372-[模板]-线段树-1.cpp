#include <cstdio>
#include <cstdlib>

template <class T>
class SegmentTree {
    private:
        struct Node {
            T val, tag;
            Node() : val(0), tag(0) {}
        };
        
        Node* d;

        void pushDown(int s, int t, int root);

    public:
        SegmentTree(int n) : d((Node*) malloc((n << 2) * sizeof(Node))) {}
        void update(int l, int r, T v, int s, int t, int root);
        T query(int l, int r, int s, int t, int root);

};

template <class T>
void SegmentTree<T>::pushDown(int s, int t, int root) {
    int m = (s + t) >> 1, left = root << 1, right = (root << 1) + 1;
    d[left].val += d[root].tag * (m - s + 1);
    d[right].val += d[root].tag * (t - m);
    d[left].tag += d[root].tag;
    d[right].tag += d[root].tag;
    d[root].tag = 0;
}

template <class T>
void SegmentTree<T>::update(int l, int r, T v, int s, int t, int root) {
    if (l <= s && t <= r) {
        d[root].val += (t - s + 1) * v;
        d[root].tag += v;
        return;
    }
    int m = (s + t) >> 1, left = root << 1, right = (root << 1) + 1;
    if (d[root].tag && s != t) pushDown(s, t, root);
    if (l <= m) update(l, r, v, s, m, left);
    if (r > m) update(l, r, v, m + 1, t, right);
    d[root].val = d[left].val + d[right].val;
}

template <class T>
T SegmentTree<T>::query(int l, int r, int s, int t, int root) {
    if (l <= s && t <= r) return d[root].val;
    int m = (s + t) >> 1, left = root << 1, right = (root << 1) + 1;
    if (d[root].tag && s != t) pushDown(s, t, root);
    T res = 0;
    if (l <= m) res += query(l, r, s, m, left);
    if (r > m) res += query(l, r, m + 1, t, right);
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    SegmentTree<long long> st(n);
    for (int i = 1; i <= n; i++) {
        long long v;
        scanf("%lld", &v);
        st.update(i, i, v, 1, n, 1);   
    }
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
