// template of splay
// sam@2aliens.net
#include <cstdlib>

template <class T>
class SplayNode {
    private:
        SplayNode *L, *R, *F;
        
        void leftRotate();
        void rightRotate();

    public:
        T val;
        SplayNode(T v) : L(NULL), R(NULL), F(NULL), val(v) {}
        
        SplayNode* find(T v);
        SplayNode* insert(T v);
        SplayNode* max();
        SplayNode* min();
        SplayNode* next(T v);
        SplayNode* prev(T v);
        
        static void splay(SplayNode* x, SplayNode* &S);
        static void split(T v, SplayNode* &S, SplayNode* &x, SplayNode* &y);
        static SplayNode* join(SplayNode* x, SplayNode* y);
        static SplayNode* deleteNode(SplayNode *x, SplayNode* &S);
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
            if (y->L == x) x->rightRotate(); // zig(x)
            else x->leftRotate();            // zag(x)
        } else {
            if (y->L == x && z->L == y) {
                y->rightRotate();            // zig(y) - zig(x)
                x->rightRotate();
            } else if (y->L == x && z->R == y) {
                x->rightRotate();            // zig(x) - zag(x)
                x->leftRotate();
            } else if (y->R == x && z->R == y) {
                y->leftRotate();             // zag(y) - zag(x)
                x->leftRotate();
            } else {
                x->leftRotate();             // zag(x) - zig(x)
                x->rightRotate();
            }
        }
    }
    S = x;
}

template <class T>
SplayNode<T>* SplayNode<T>::find(T v) {
    if (v == val) return this;
    if (v < val) {
        if (!L) return NULL;
        return L->find(v);
    } else {
        if (!R) return NULL;
        return R->find(v);
    }
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
SplayNode<T>* SplayNode<T>::deleteNode(SplayNode<T>* x, SplayNode<T>* &S) {
    splay(x, S);
    SplayNode* a = x->L;
    SplayNode* b = x->R;
    delete x;
    if (a) a->F = NULL;
    if (b) b->F = NULL;
    if (!a) return b;
    if (!b) return a;
    return join(a, b);
}

template <class T>
SplayNode<T>* SplayNode<T>::max() {
    if (!R) return this;
    return R->max();
}

template <class T>
SplayNode<T>* SplayNode<T>::min() {
    if (!L) return this;
    return L->min();
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

template <class T>
SplayNode<T>* SplayNode<T>::join(SplayNode<T>* x, SplayNode<T>* y) {
    SplayNode* p = x->max();
    splay(p, x);
    p->R = y;
    y->F = p;
    return p;
}

template <class T>
void SplayNode<T>::split(T k, SplayNode<T>* &S, SplayNode<T>* &x, SplayNode<T>* &y) {
    SplayNode* p = S->find(k);
    splay(p, S);
    x = p->L;
    y = p->R;
}
