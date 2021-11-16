#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

template <class T>
class SplayNode {
    private:
        SplayNode *L, *R, *F;

        void leftRotate();
        void rightRotate();

    public:
        T val;
        SplayNode(T v) : L(NULL), R(NULL), F(NULL), val(v) {}

        SplayNode* insert(T v);
        SplayNode* next(T v);
        SplayNode* prev(T v);

        static void splay(SplayNode* x, SplayNode* &S);
};

template <class T>
void SplayNode<T>::rightRotate() {
    SplayNode* y = F;
    F = y->F;
    if (F) {
        if (F->L == y) F->L = this;
        else F->R = this;
    }
    if (R) R->F = y;
    y->L = R;
    y->F = this;
    this->R = y;
}

template <class T>
void SplayNode<T>::leftRotate() {
    SplayNode* y = F;
    F = y->F;
    if (F) {
        if (F->L == y) F->L = this;
        else F->R = this;
    }
    if (L) L->F = y;
    y->R = L;
    y->F = this;
    this->L = y;
}

template <class T>
void SplayNode<T>::splay(SplayNode* x, SplayNode* &S) {
    while (x->F) {
        SplayNode* y = x->F;
        SplayNode* z = y->F;
        if (!z) {
            if (y->L == x) x->rightRotate();
            else x->leftRotate();
        } else {
            if (y->L == x && z->L == y) {
                y->rightRotate();
                x->rightRotate();
            } else if (y->L == x && z->R == y) {
                x->rightRotate();
                x->leftRotate();
            } else if (y->R == x && z->R == y) {
                y->leftRotate();
                x->leftRotate();
            } else {
                x->leftRotate();
                x->rightRotate();
            }
        }
    }
    S = x;
}

template <class T>
SplayNode<T>* SplayNode<T>::insert(T v) {
    if (v <= val) {
        if (!L) {
            L = new SplayNode(v);
            L->F = this;
            return L;
        } else return L->insert(v);
    } else {
        if (!R) {
            R = new SplayNode(v);
            R->F = this;
            return R;
        } else return R->insert(v);
    }
}

template <class T>
SplayNode<T>* SplayNode<T>::prev(T v) {
    if (val <= v) {
        if (!R) return this;
        SplayNode* tmp = R->prev(v);
        if (!tmp) return this;
        return tmp;
    } else {
        if (!L) return NULL;
        return L->prev(v);
    }
}

template <class T>
SplayNode<T>* SplayNode<T>::next(T v) {
    if (v <= val) {
        if (!L) return this;
        SplayNode* tmp = L->next(v);
        if (!tmp) return this;
        return tmp;
    } else {
        if (!R) return NULL;
        return R->next(v);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    SplayNode<int>* root = new SplayNode<int>(k);
    int ans = k;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &k);
        SplayNode<int>* pre = root->prev(k);
        if (pre) SplayNode<int>::splay(pre, root);
        SplayNode<int>* nex = root->next(k);
        if (nex) SplayNode<int>::splay(nex, root);
        if (!pre) ans += nex->val - k;
        else if (!nex) ans += k - pre->val;
        else ans += std::min(k - pre->val, nex->val - k);
        SplayNode<int>* x = root->insert(k);
        SplayNode<int>::splay(x, root);
    }
    printf("%d", ans);
    return 0;
}
