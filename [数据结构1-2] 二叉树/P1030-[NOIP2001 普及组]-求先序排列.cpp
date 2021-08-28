#include <cstdio>
#include <cstring>

const int MAXN = 9;

char inOrder[MAXN], postOrder[MAXN];

struct Node {
    char val;
    Node *left, *right;
    Node(char _val, Node* _left, Node* _right) : val(_val), left(_left), right(_right) {}
};

Node* create(int inL, int inR, int postL, int postR) {
    if (postL > postR) return NULL;
    Node* root = new Node(postOrder[postR], NULL, NULL);
    int k;
    for (k = inL; k <= inR; k++) {
        if (inOrder[k] == postOrder[postR]) break;
    }
    int numL = k - inL;
    root->left = create(inL, k - 1, postL, postL + numL - 1);
    root->right = create(k + 1, inR, postL + numL, postR - 1);
    return root;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%c", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    scanf("%s %s", inOrder, postOrder);
    int n = strlen(inOrder);
    Node* root = create(0, n - 1, 0, n - 1);
    preOrder(root);
    return 0;
}
