#include <cstdio>
#include <cstdlib>

struct Node {
    long long val, tag;
    int s, t;
    Node *lChild, *rChild;
};

void build(Node* &cur, int l, int r) {
    cur->s = l;
    cur->t = r;
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
    cur->lChild->val += cur->tag * (cur->lChild->t - cur->lChild->s);
    cur->rChild->val += cur->tag * (cur->rChild->t - cur->rChild->s);
    cur->lChild->tag += cur->tag;
    cur->rChild->tag += cur->tag;
    cur->tag = 0;
}

long long query(Node* cur, int l, int r) {
    if (l <= cur->s && cur->t <= r) return cur->val;
    if (cur->tag) pushDown(cur);
    long long res = 0;
    if (l < (cur->s + cur->t) >> 1) res += query(cur->lChild, l, r);
    if (r > (cur->s + cur->t) >> 1) res += query(cur->rChild, l, r);
    return res;
}

void update(Node* &cur, int l, int r, long long x) {
    if (l <= cur->s && cur->t <= r) {
        cur->val += x * (cur->t - cur->s);
        cur->tag += x;
        return;
    }
    if (cur->tag) pushDown(cur);
    if (l < (cur->s + cur->t) >> 1) update(cur->lChild, l, r, x);
    if (r > (cur->s + cur->t) >> 1) update(cur->rChild, l, r, x);
    cur->val = cur->lChild->val + cur->rChild->val;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Node* root = new Node;
    build(root, 1, n + 1);
    for (int i = 1; i <= n; i++) {
        long long v;
        scanf("%lld", &v);
        update(root, i, i + 1, v);
    }
    while (m--) {
        int opt, x, y, k;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) {
            scanf("%d", &k);
            update(root, x, y + 1, k);
        } else {
            printf("%lld\n", query(root, x, y + 1));
        }
    }
    return 0;
}
