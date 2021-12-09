// template of segment tree
// OI style
// sam@2aliens.net
#include <cstdlib>

struct Node {
    int val, tag, st, ed;
    Node *lChild, *rChild;
};

void build(Node* &cur, int l, int r) {
    cur->st = l;
    cur->ed = r;
    cur->val = 0;
    cur->tag = 0;
    if (l + 1 == r) {
        cur->lChild = cur->rChild = NULL;
        return;
    }
    cur->lChild = new Node;
    cur->rChild = new Node;
    build(cur->lChild, l, (l + r) >> 1);
    build(cur->rChild, (l + r) >> 1, r);
}

void pushDown(Node* &cur) {
    cur->lChild->val += cur->tag * (cur->lChild->ed - cur->lChild->st);
    cur->rChild->val += cur->tag * (cur->rChild->ed - cur->rChild->st);
    cur->lChild->tag += cur->tag;
    cur->rChild->tag += cur->tag;
    cur->tag = 0;
}

int query(Node* cur, int l, int r) {
    if (l <= cur->st && cur->ed <= r) return cur->val;
    if (cur->tag) pushDown(cur);
    int res = 0;
    if (l < (cur->st + cur->ed) >> 1) res += query(cur->lChild, l, r);
    if (r > (cur->st + cur->ed) >> 1) res += query(cur->rChild, l, r);
    return res;
}

void update(Node* &cur, int l, int r, int x) {
    if (l <= cur->st && cur->ed <= r) {
        cur->val += x * (cur->ed - cur->st);
        cur->tag += x;
        return;
    }
    if (cur->tag) pushDown(cur);
    if (l < (cur->st + cur->ed) >> 1) update(cur->lChild, l, r, x);
    if (r > (cur->st + cur->ed) >> 1) update(cur->rChild, l, r, x);
    cur->val = cur->lChild->val + cur->rChild->val;
}
