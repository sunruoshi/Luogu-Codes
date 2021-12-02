#include <cstdlib>

struct SplayNode {
    int val;
    SplayNode *L, *R, *F;
    SplayNode(int x) : val(x), L(NULL), R(NULL), F(NULL) {}
};

void rightRotate(SplayNode* &cur) {
    SplayNode* y = cur->F;
    cur->F = y->F;
    if (cur->F) {
        if (y == cur->F->L) cur->F->L = cur;
        else cur->F->R = cur;
    }
    if (cur->R) cur->R->F = y;
    y->L = cur->R;
    y->F = cur;
    cur->R = y;
}

void leftRotate(SplayNode* &cur) {
    SplayNode* y = cur->F;
    cur->F = y->F;
    if (cur->F) {
        if (y == cur->F->L) cur->F->L = cur;
        else cur->F->R = cur;
    }
    if (cur->L) cur->L->F = y;
    y->R = cur->L;
    y->F = cur;
    cur->L = y;
}

void splay(SplayNode* x, SplayNode* &root) {
    while (x->F) {
        SplayNode* y = x->F;
        SplayNode* z = y->F;
        if (!z) {
            if (x == y->L) rightRotate(x);
            else leftRotate(x);
        } else {
            if (x == y->L && y == z->L) {
                rightRotate(y);
                rightRotate(x);
            } else if (x == y->L && y == z->R) {
                rightRotate(x);
                leftRotate(x);
            } else if (x == y->R && y == z->R) {
                leftRotate(y);
                leftRotate(x);
            } else {
                leftRotate(x);
                rightRotate(x);
            }
        }
    }
    root = x;
}

SplayNode* insert(SplayNode* &cur, int x) {
    if (x <= cur->val) {
        if (!cur->L) {
            cur->L = new SplayNode(x);
            cur->L->F = cur;
            return cur->L;
        } else return insert(cur->L, x);
    } else {
        if (!cur->R) {
            cur->R = new SplayNode(x);
            cur->R->F = cur;
            return cur->R;
        } else return insert(cur->R, x);
    }
}

SplayNode* findNode(int x, SplayNode* cur) {
    if (x == cur->val) return cur;
    if (x < cur->val) {
        if (!cur->L) return NULL;
        return findNode(x, cur->L);
    } else {
        if (!cur->R) return NULL;
        return findNode(x, cur->R);
    }
}

SplayNode* findMax(SplayNode* cur) {
    if (!cur->R) return cur;
    return findMax(cur->R);
}

SplayNode* findMin(SplayNode* cur) {
    if (!cur->L) return cur;
    return findMin(cur->L);
}

SplayNode* findPred(SplayNode* cur, int x) {
    if (x >= cur->val) {
        if (!cur->R) return cur;
        SplayNode* res = findPred(cur->R, x);
        if (!res) return cur;
        return res;
    } else {
        if (!cur->L) return NULL;
        return findPred(cur->L, x);
    }
}

SplayNode* findSucc(SplayNode* cur, int x) {
    if (x <= cur->val) {
        if (!cur->L) return cur;
        SplayNode* res = findSucc(cur->L, x);
        if (!res) return cur;
        return res;
    } else {
        if (!cur->R) return NULL;
        return findSucc(cur->R, x);
    }
}

SplayNode* join(SplayNode* x, SplayNode* y) {
    SplayNode* p = findMax(x);
    splay(p, x);
    p->R = y;
    y->F = p;
    return p;
}

SplayNode* deleteNode(SplayNode* x, SplayNode* &root) {
    splay(x, root);
    SplayNode *a = x->L, *b = x->R;
    delete x;
    if (a) a->F = NULL;
    if (b) b->F = NULL;
    if (!a) return b;
    if (!b) return a;
    return join(a, b);
}

void split(int k, SplayNode* &root, SplayNode* &x, SplayNode* &y) {
    SplayNode* p = findNode(k, root);
    splay(p, root);
    x = p->L;
    y = p->R;
}
