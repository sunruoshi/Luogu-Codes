#include <iostream>
using namespace std;

struct SplayNode {
    int val;
    SplayNode *L, *R, *F;
    SplayNode(int x) : val(x), L(NULL), R(NULL), F(NULL) {}

    void rightRotate();
    void leftRotate();
    static void splay(SplayNode* x, SplayNode* &root);

    SplayNode* insert(int x);
    SplayNode* pred(int x);
    SplayNode* succ(int x);
};

void SplayNode::rightRotate() {
    SplayNode* y = F;
    F = y->F;
    if (F) {
        if (y == F->L) F->L = this;
        else F->R = this;
    }
    if (R) R->F = y;
    y->L = R;
    y->F = this;
    this->R = y;
}

void SplayNode::leftRotate() {
    SplayNode* y = F;
    F = y->F;
    if (F) {
        if (y == F->L) F->L = this;
        else F->R = this;
    }
    if (L) L->F = y;
    y->R = L;
    y->F = this;
    this->L = y;
}

void SplayNode::splay(SplayNode* x, SplayNode* &root) {
    while (x->F) {
        SplayNode* y = x->F;
        SplayNode* z = y->F;
        if (!z) {
            if (x == y->L) x->rightRotate();
            else x->leftRotate();
        } else {
            if (x == y->L && y == z->L) {
                y->rightRotate();
                x->rightRotate();
            } else if (x == y->L && y == z->R) {
                x->rightRotate();
                x->leftRotate();
            } else if (x == y->R && y == z->R) {
                y->leftRotate();
                x->leftRotate();
            } else {
                x->leftRotate();
                x->rightRotate();
            }
        }
    }
    root = x;
}

SplayNode* SplayNode::insert(int x) {
    if (x <= val) {
        if (!L) {
            L = new SplayNode(x);
            L->F = this;
            return L;
        } else return L->insert(x);
    } else {
        if (!R) {
            R = new SplayNode(x);
            R->F = this;
            return R;
        } else return R->insert(x);
    }
}

SplayNode* SplayNode::pred(int x) {
    if (x >= val) {
        if (!R) return this;
        SplayNode* res = R->pred(x);
        if (!res) return this;
        return res;
    } else {
        if (!L) return NULL;
        return L->pred(x);
    }
}

SplayNode* SplayNode::succ(int x) {
    if (x <= val) {
        if (!L) return this;
        SplayNode* res = L->succ(x);
        if (!res) return this;
        return res;
    } else {
        if (!R) return NULL;
        return R->succ(x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    SplayNode* root = new SplayNode(k);
    int ans = k;
    for (int i = 2; i <= n; i++) {
        cin >> k;
        SplayNode* pred = root->pred(k);
        if (pred) SplayNode::splay(pred, root);
        SplayNode* succ = root->succ(k);
        if (succ) SplayNode::splay(succ, root);
        if (!pred) ans += succ->val - k;
        else if (!succ) ans += k - pred->val;
        else ans += min(k - pred->val, succ->val - k);
        SplayNode* x = root->insert(k);
        SplayNode::splay(x, root);
    }
    cout << ans;
}
