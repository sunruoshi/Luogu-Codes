// template of segment tree
// dynamic version
// sam@2aliens.net
#include <cstdlib>

template <class T>
class STNode {
    private:
        int st, ed;                       // range [st, ed)
        T val, tag;                       // sum of range [st, ed), lazytag
        STNode *lChild, *rChild;

        void pushDown();                  // push down the lazytag

    public:
        void build(int l, int r);         // build with new root & range [l, r)
        T query(int l, int r);            // query sum of range [l, r)
        void update(int l, int r, T v);   // add v for all elements in range [l, r)
};

template <class T>
void STNode<T>::build(int l, int r) {
    this->st = l;
    this->ed = r;
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
    this->lChild->val += this->tag * (this->lChild->ed - this->lChild->st);
    this->rChild->val += this->tag * (this->rChild->ed - this->rChild->st);
    this->lChild->tag += this->tag;
    this->rChild->tag += this->tag;
    this->tag = 0;
}

template <class T>
T STNode<T>::query(int l, int r) {
    if (l <= this->st && this->ed <= r) return this->val;
    if (this->tag) this->pushDown();
    T res = 0;
    if (l < (this->st + this->ed) >> 1) res += this->lChild->query(l, r);
    if (r > (this->st + this->ed) >> 1) res += this->rChild->query(l, r);
    return res;
}

template <class T>
void STNode<T>::update(int l, int r, T v) {
    if (l <= this->st && this->ed <= r) {
        this->val += v * (this->ed - this->st);
        this->tag += v;
        return;
    }
    if (this->tag) this->pushDown();
    if (l < (this->st + this->ed) >> 1) this->lChild->update(l, r, v);
    if (r > (this->st + this->ed) >> 1) this->rChild->update(l, r, v);
    this->val = this->lChild->val + this->rChild->val;
}
