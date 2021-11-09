#include <cstdio>
#include <cstdlib>

template <class T>
class STNode {
    private:
        int s, t;
        T val, tag;
        STNode *lChild, *rChild;

        void pushDown();

    public:
        void build(int l, int r);
        T query(int l, int r);
        void update(int l, int r, T v);
};

template <class T>
void STNode<T>::build(int l, int r) {
    this->s = l;
    this->t = r;
    this->val = 0;
    this->tag = 0;
    if (l + 1 == r) {
        this->lChild = this->rChild = NULL;
        return;
    }
    this->lChild = new STNode;
    this->rChild = new STNode;
    this->lChild->build(l, (l + r) >> 1);
    this->rChild->build((l + r) >> 1, r);
}

template <class T>
void STNode<T>::pushDown() {
    this->lChild->val += this->tag * (this->lChild->t - this->lChild->s);
    this->rChild->val += this->tag * (this->rChild->t - this->rChild->s);
    this->lChild->tag += this->tag;
    this->rChild->tag += this->tag;
    this->tag = 0;
}

template <class T>
T STNode<T>::query(int l, int r) {
    if (l <= this->s && this->t <= r) return this->val;
    if (this->tag) this->pushDown();
    T res = 0;
    if (l < (this->s + this->t) >> 1) res += this->lChild->query(l, r);
    if (r > (this->s + this->t) >> 1) res += this->rChild->query(l, r);
    return res;
}

template <class T>
void STNode<T>::update(int l, int r, T v) {
    if (this->s + 1 == this->t) {
        this->val += v * (this->t - this->s);
        this->tag += v;
        return;
    }
    if (this->tag) this->pushDown();
    if (l < (this->s + this->t) >> 1) this->lChild->update(l, r, v);
    if (r > (this->s + this->t) >> 1) this->rChild->update(l, r, v);
    this->val = this->lChild->val + this->rChild->val;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    STNode<long long>* root = new STNode<long long>;
    root->build(1, n + 1);
    for (int i = 1; i <= n; i++) {
        long long v;
        scanf("%lld", &v);
        root->update(i, i + 1, v);
    }
    while (m--) {
        int opt, x, y, k;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) {
            scanf("%d", &k);
            root->update(x, y + 1, k);
        } else {
            printf("%lld\n", root->query(x, y + 1));
        }
    }
    return 0;
}
