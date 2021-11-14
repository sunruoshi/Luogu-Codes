// template of segment tree
// static version
// sam@2aliens.net
#include <cstdlib>

template <class T>
class SegmentTree {
    private:
        struct Node {
            int s, t;
            T val, tag;
            Node() : val(0), tag(0) {}
        };

        Node* d;

        void pushDown(int cur);

    public:
        SegmentTree(int n) : d((Node*) malloc((n << 2) * sizeof(Node))) {}
        void build(int cur, int l, int r);
        void update(int l, int r, T v, int cur);
        T query(int l, int r, int cur);

};

template <class T> 
void SegmentTree<T>::build(int cur, int l, int r) {
    d[cur].s = l;
    d[cur].t = r;
    if (l + 1 == r) return;
    build(cur << 1, l, (l + r) >> 1);
    build((cur << 1) + 1, (l + r) >> 1, r);
}

template <class T>
void SegmentTree<T>::pushDown(int cur) {
    int lChild = cur << 1, rChild = (cur << 1) + 1;
    d[lChild].val += d[cur].tag * (d[lChild].t - d[lChild].s);
    d[rChild].val += d[cur].tag * (d[rChild].t - d[rChild].s);
    d[lChild].tag += d[cur].tag;
    d[rChild].tag += d[cur].tag;
    d[cur].tag = 0;
}

template <class T>
void SegmentTree<T>::update(int l, int r, T v, int cur) {
    if (l <= d[cur].s && d[cur].t <= r) {
        d[cur].val += (d[cur].t - d[cur].s) * v;
        d[cur].tag += v;
        return;
    }
    int lChild = cur << 1, rChild = (cur << 1) + 1;
    if (d[cur].tag) pushDown(cur);
    if (l < (d[cur].s + d[cur].t) >> 1) update(l, r, v, lChild);
    if (r > (d[cur].s + d[cur].t) >> 1) update(l, r, v, rChild);
    d[cur].val = d[lChild].val + d[rChild].val;
}

template <class T>
T SegmentTree<T>::query(int l, int r, int cur) {
    if (l <= d[cur].s && d[cur].t <= r) return d[cur].val;
    int lChild = cur << 1, rChild = (cur << 1) + 1;
    if (d[cur].tag) pushDown(cur);
    T res = 0;
    if (l < (d[cur].s + d[cur].t) >> 1) res += query(l, r, lChild);
    if (r > (d[cur].s + d[cur].t) >> 1) res += query(l, r, rChild);
    return res;
}
