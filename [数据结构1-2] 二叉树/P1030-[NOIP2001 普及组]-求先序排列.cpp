#include <cstdio>
#include <cstring>

const int MAXN = 9;

char inOrder[MAXN], postOrder[MAXN];

struct Node {
    char val;
    int left, right;
    Node() {}
    Node(char _val, int _left, int _right) : val(_val), left(_left), right(_right) {}
} node[MAXN];

int idx;

int newNode(char v) {
    node[idx] = Node(v, -1, -1);
    return idx++;
}

int create(int inL, int inR, int postL, int postR) {
    if (postL > postR) return -1;
    int root = newNode(postOrder[postR]), k;
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
    scanf("%s %s", inOrder, postOrder);
    int n = strlen(inOrder);
    int root = create(0, n - 1, 0, n - 1);
    preOrder(root);
    return 0;
}
