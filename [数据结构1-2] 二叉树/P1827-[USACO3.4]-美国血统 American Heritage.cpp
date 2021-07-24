#include <iostream>
#include <string>
using namespace std;

const int MAXN = 26;

string inOrder, preOrder;

struct Node {
    char val;
    int left, right;
    Node() {}
    Node(char _val, int _left, int _right) {
        val = _val;
        left = _left;
        right = _right;
    }
} node[MAXN];

int idx = 0;

int newNode(char v) {
    node[idx] = Node(v, -1, -1);
    return idx++;
}

int create(int inL, int inR, int preL, int preR) {
    if (preL > preR) return -1;
    int root = newNode(preOrder[preL]);
    int k;
    for (k = inL; k <= inR; k++) {
        if (inOrder[k] == preOrder[preL]) break;
    }
    int numL = k - inL;
    node[root].left = create(inL, k - 1, preL + 1, preL + numL);
    node[root].right = create(k + 1, inR, preL + numL + 1, preR);
    return root;
}

void postOrder(int root) {
    if (root == -1) return;
    postOrder(node[root].left);
    postOrder(node[root].right);
    cout << node[root].val;
}

int main() {
    cin >> inOrder >> preOrder;
    int len = inOrder.size();
    int root = create(0, len - 1, 0, len - 1);
    postOrder(root);
    return 0;
}
