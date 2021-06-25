#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8;

string inOrder, postOrder;

struct Node {
    char val;
    int left, right;
} node[MAXN];

int idx = 0;

int newNode(char v) {
    node[idx].val = v;
    node[idx].left = -1;
    node[idx].right = -1;
    return idx++;
}

int create(int inL, int inR, int postL, int postR) {
    if (postL > postR) return -1;
    int root = newNode(postOrder[postR]);
    int k;
    for (k = inL; k <= inR; k++) {
        if (inOrder[k] == postOrder[postR]) break;
    }
    int numL = k - inL;
    node[root].left = create(inL, k - 1, postL, postL + numL - 1);
    node[root].right = create(k + 1, inR, postL + numL, postR - 1);
    return root;
}

void preOrder(int root) {
    if (root == -1) return;
    printf("%c", node[root].val);
    preOrder(node[root].left);
    preOrder(node[root].right);
}

int main() {
    cin >> inOrder >> postOrder;
    int len = inOrder.size();
    int root = create(0, len - 1, 0, len - 1);
    preOrder(root);
    return 0;
}
