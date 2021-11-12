#include <cstdlib>

template <class T>
class SplayNode {
    private:
        SplayNode *L, *R, *F; // left-child, right-child, father
        
        void leftRotate();
        void rightRotate();
        
        static void splay(SplayNode* x, SplayNode* S);

    public:
        T key; // key value
        SplayNode(T k) : L(NULL), R(NULL), F(NULL), key(k) {}
        
        SplayNode* find(T k);
        SplayNode* insert(T k);
        SplayNode* max();
        SplayNode* min();
        SplayNode* next(T k);
        SplayNode* prev(T k);
        
        static void split(T k, SplayNode* S, SplayNode* &x, SplayNode* &y);
        static void maintain(SplayNode* x, SplayNode* &S);
        static SplayNode* join(SplayNode* x, SplayNode* y);
        static SplayNode* deleteNode(SplayNode *x, SplayNode* S);
};

template <class T>
void SplayNode<T>::leftRotate() {
    SplayNode* y = F;
    F = y->F;                         // set father of x to father of y
    if (F != NULL) {
        if (F->L == y) F->L = this;   // if y is a left-child, set x to a left-child
        else F->R = this;             // else set x to a right-child
    }
    if (R != NULL) R->F = y;          // set father of right-child to y
    y->L = R;                         // set left-child of y to right-child of x
    y->F = this;                      // set father of y to x
    this->R = y;                      // set right-child of x to y
}

template <class T>
void SplayNode<T>::rightRotate() {
    SplayNode* y = F;
    F = y->F;
    if (F != NULL) {
        if (F->L == y) F->L = this;
        else F->R = this;
    }
    if (L != NULL) L->F = y;          // set father of left-child to y
    y->R = L;                         // set right-child of y to left-child of x
    y->F = this;
    this->L = y;                      // set left-child of x to y
}

template <class T>
void SplayNode<T>::splay(SplayNode* x, SplayNode* S) {
    SplayNode* root = S->F;
    while (x->F != root) {
        SplayNode* y = x->F;
        SplayNode* z = y->F;
        if (z == root) {
            if (y->L == x) x->leftRotate(); // zig(x)
            else x->rightRotate();          // zag(x)
        } else {
            if (y->L == x && z->L == y) {
                y->leftRotate();            // zig(y) - zig(x)
                x->leftRotate();
            } else if (y->L == x && z->R == y) {
                x->leftRotate();            // zig(x) - zag(x)
                x->rightRotate();
            } else if (y->R == x && z->R == y) {
                y->rightRotate();           // zag(y) - zag(x)
                x->rightRotate();
            } else {
                x->rightRotate();           // zag(x) - zig(x)
                x->leftRotate();
            }
        }
    }
}

template <class T>
void SplayNode<T>::maintain(SplayNode* x, SplayNode* &S) {
    splay(x, S);
    S = x;
}

template <class T>
SplayNode<T>* SplayNode<T>::find(T k) { // splay x to root after found x
    if (k == key) return this;
    if (k < key) {
        if (L == NULL) return NULL;
        return L->find(k);
    } else {
        if (R == NULL) return NULL;
        return R->find(k);
    }
}

template <class T>
SplayNode<T>* SplayNode<T>::insert(T k) { // splay x to root after inserted x
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

template <class T>
SplayNode<T>* SplayNode<T>::deleteNode(SplayNode<T>* x, SplayNode<T>* S) {
    splay(x, S);
    SplayNode* a = x->L;
    SplayNode* b = x->R;
    delete x;
    if (a != NULL) a->F = NULL;
    if (b != NULL) b->F = NULL;
    if (a == NULL) return b;
    if (b == NULL) return a;
    return join(a, b);
}

template <class T>
SplayNode<T>* SplayNode<T>::max() {
    if (R == NULL) return this;
    return R->max();
}

template <class T>
SplayNode<T>* SplayNode<T>::min() {
    if (L == NULL) return this;
    return L->min();
}

template <class T>
SplayNode<T>* SplayNode<T>::prev(T k) {
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

template <class T>
SplayNode<T>* SplayNode<T>::next(T k) {
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

template <class T>
SplayNode<T>* SplayNode<T>::join(SplayNode<T>* x, SplayNode<T>* y) {
    SplayNode* p = x->max();
    splay(p, x);
    p->R = y;
    y->F = p;
    return p;
}

template <class T>
void SplayNode<T>::split(T k, SplayNode<T>* S, SplayNode<T>* &x, SplayNode<T>* &y) {
    SplayNode* p = S->find(k);
    splay(p, S);
    x = p->L;
    y = p->R;
}
