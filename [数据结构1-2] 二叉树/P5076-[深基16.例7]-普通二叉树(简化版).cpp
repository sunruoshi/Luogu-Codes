#include <iostream>
using namespace std;

const int INF = (unsigned) (1 << 31) - 1;

struct Node {
    int val, size, cnt;
    Node *L, *R;
    Node(int x) : val(x), size(1), cnt(1), L(NULL), R(NULL) {}
};

void insert(Node* &cur, int x) {
    if (!cur) {
        cur = new Node(x);
        return;
    }
    cur->size++;
    if (x < cur->val) insert(cur->L, x);
    else if (x > cur->val) insert(cur->R, x);
    else cur->cnt++;
}

Node* findPred(Node* cur, int x) {
    if (x > cur->val) {
        if (!cur->R) return cur;
        Node* res = findPred(cur->R, x);
        if (!res) return cur;
        return res;
    } else {
        if (!cur->L) return NULL;
        else return findPred(cur->L, x);
    }
}

Node* findSucc(Node* cur, int x) {
    if (x < cur->val) {
        if (!cur->L) return cur;
        Node* res = findSucc(cur->L, x);
        if (!res) return cur;
        return res;
    } else {
        if (!cur->R) return NULL;
        else return findSucc(cur->R, x);
    }
}

int getRank(Node* cur, int x) {
    int sizeL = cur->L ? cur->L->size : 0;
    if (cur->L && x < cur->val) return getRank(cur->L, x);
    if (cur->R && x > cur->val) return getRank(cur->R, x) + sizeL + cur->cnt;
    return sizeL + 1;
}

Node* findRank(Node* cur, int x) {
    int sizeL = cur->L ? cur->L->size : 0;
    if (cur->L && x <= sizeL) return findRank(cur->L, x);
    if (cur->R && x > sizeL + cur->cnt) return findRank(cur->R, x - sizeL - cur->cnt);
    return cur;
}

int main() {
    int q, opt, x;
    cin >> q;
    Node* root = NULL;
    while (q--) {
        cin >> opt >> x;
        if (opt == 1) {
            cout << getRank(root, x) << endl;
        } else if (opt == 2) {
            cout << findRank(root, x)->val << endl;
        } else if (opt == 3) {
            Node* pred = findPred(root, x);
            cout << (pred ? pred->val : -INF) << endl;
        } else if (opt == 4) {
            Node* succ = findSucc(root, x);
            cout << (succ ? succ->val : INF) << endl;
        } else if (opt == 5) {
            if (root) insert(root, x);
            else root = new Node(x);
        }
    }
    return 0;
}
