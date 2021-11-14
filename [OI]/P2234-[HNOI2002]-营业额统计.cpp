#include <cstdio>
#include <cstdlib>
#include <algorithm>

class SplayNode {
    private:
        SplayNode *L, *R, *F;

        void leftRotate();
        void rightRotate();

    public:
        int key;

        SplayNode(int k) : L(NULL), R(NULL), F(NULL), key(k) {}
        
        SplayNode* insert(int k);
        SplayNode* next(int k);
        SplayNode* prev(int k);
        static void splay(SplayNode* x, SplayNode* &S);
};

void SplayNode::leftRotate() {
    SplayNode* y = F;
    F = y->F;
    if (F != NULL) {
        if (F->L == y) F->L = this;
        else F->R = this;
    }
    if (R != NULL) R->F = y;
    y->L = R;
    y->F = this;
    this->R = y;
}

void SplayNode::rightRotate() {
    SplayNode* y = F;
    F = y->F;
    if (F != NULL) {
        if (F->L == y) F->L = this;
        else F->R = this;
    }
    if (L != NULL) L->F = y;
    y->R = L;
    y->F = this;
    this->L = y;
}

void SplayNode::splay(SplayNode* x, SplayNode* &S) {
    SplayNode* root = S->F;
    while (x->F != root) {
        SplayNode* y = x->F;
        SplayNode* z = y->F;
        if (z == root) {
            if (y->L == x) x->leftRotate();
            else x->rightRotate();
        } else {
            if (y->L == x && z->L == y) {
                y->leftRotate();
                x->leftRotate();
            } else if (y->L == x && z->R == y) {
                x->leftRotate();
                x->rightRotate();
            } else if (y->R == x && z->R == y) {
                y->rightRotate();
                x->rightRotate();
            } else {
                x->rightRotate();
                x->leftRotate();
            }
        }
    }
    S = x;
}

SplayNode* SplayNode::insert(int k) {
    if (k <= key) {
        if (L == NULL) {
            L = new SplayNode(k);
            L->F = this;
            return L;
        } else return L->insert(k);
    } else {
        if (R == NULL) {
            R = new SplayNode(k);
            R->F = this;
            return R;
        } else return R->insert(k);
    }
}

SplayNode* SplayNode::prev(int k) {
    if (key <= k) {
        if (R == NULL) return this;
        SplayNode* tmp = R->prev(k);
        if (tmp == NULL) return this;
        return tmp;
    } else {
        if (L == NULL) return NULL;
        return L->prev(k);
    }
}

SplayNode* SplayNode::next(int k) {
    if (k <= key) {
        if (L == NULL) return this;
        SplayNode* tmp = L->next(k);
        if (tmp == NULL) return this;
        return tmp;
    } else {
        if (R == NULL) return NULL;
        return R->next(k);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    SplayNode* root = new SplayNode(k);
    int ans = k;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &k);
        SplayNode* pre = root->prev(k);
        if (pre != NULL) SplayNode::splay(pre, root);
        SplayNode* nex = root->next(k);
        if (nex != NULL) SplayNode::splay(nex, root);
        if (pre == NULL) ans += nex->key - k;
        else if (nex == NULL) ans += k - pre->key;
        else ans += std::min(k - pre->key, nex->key - k);
        SplayNode* x = root->insert(k);
        SplayNode::splay(x, root);
    }
    printf("%d", ans);
    return 0;
}
