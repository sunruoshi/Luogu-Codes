#include <cstdio>
#include <cstdlib>

template <class T>
class STNode {
    private:
        int s, t;
        T val, tag;
        STNode *lChild, *rChild;

        void pushDown(STNode* cur);

    public:
        static void build(STNode* cur, int l, int r);
        static T query(STNode* cur, int l, int r);
        static void update(STNode* cur, int l, int r, T tag);
};

template <class T>
void STNode<T>::build(STNode<T>* cur, int l, int r) {
    cur->s = l;
    cur->t = r;
    cur->val = 0;
    cur->tag = 0;
    if (l + 1 == r) {
        cur->lChild = cur->rChild = NULL;
        return;
    }
    cur->lChild = new STNode;
    cur->rChild = new STNode;
    build(cur->lChild, l, (l + r) >> 1);
    build(cur->rChild, (l + r) >> 1, r);
}

template <class T>
void STNode<T>::pushDown(STNode<T>* cur) {
    cur->lChild->val += cur->tag * (cur->lChild->t - cur->lChild->s);
    cur->rChild->val += cur->tag * (cur->rChild->t - cur->rChild->s);
    cur->lChild->tag += cur->tag;
    cur->rChild->tag += cur->tag;
    cur->tag = 0;
}

template <class T>
T STNode<T>::query(STNode<T>* cur, int l, int r) {
    if (l <= cur->s && cur->t <= r) return cur->val;
    if (cur->tag) cur->pushDown(cur);
    T res = 0;
    if (l < (cur->s + cur->t) >> 1) res += query(cur->lChild, l, r);
    if (r > (cur->s + cur->t) >> 1) res += query(cur->rChild, l, r);
    return res;
}

template <class T>
void STNode<T>::update(STNode<T>* cur, int l, int r, T v) {
    if (cur->s + 1 == cur->t) {
        cur->val += v * (cur->t - cur->s);
        cur->tag += v;
        return;
    }
    if (cur->tag) cur->pushDown(cur);
    if (l < (cur->s + cur->t) >> 1) update(cur->lChild, l, r, v);
    if (r > (cur->s + cur->t) >> 1) update(cur->rChild, l, r, v);
    cur->val = cur->lChild->val + cur->rChild->val;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    STNode<long long>* root = new STNode<long long>;
    STNode<long long>::build(root, 1, n + 1);
    for (int i = 1; i <= n; i++) {
        long long v;
        scanf("%lld", &v);
        STNode<long long>::update(root, i, i + 1, v);
    }
    while (m--) {
        int opt, x, y, k;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) {
            scanf("%d", &k);
            STNode<long long>::update(root, x, y + 1, k);
        } else {
            printf("%lld\n", STNode<long long>::query(root, x, y + 1));
        }
    }
    return 0;
}
