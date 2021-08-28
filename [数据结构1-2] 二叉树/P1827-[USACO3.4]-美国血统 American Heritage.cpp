#include <cstdio>
#include <cstring>

const int MAXN = 26;

char inOrder[MAXN], preOrder[MAXN];

struct Node {
    char val;
    Node *left, *right;
    Node(char _val, Node* _left, Node* _right) : val(_val) , left(_left), right(_right) {}
};

Node* create(int inL, int inR, int preL, int preR) {
    if (preL > preR) return NULL;
    Node* root = new Node(preOrder[preL], NULL, NULL);
    int k;
    for (k = inL; k <= inR; k++) {
        if (inOrder[k] == preOrder[preL]) break;
    }
    int numL = k - inL;
    root->left = create(inL, k - 1, preL + 1, preL + numL);
    root->right = create(k + 1, inR, preL + numL + 1, preR);
    return root;
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->val);
}

int main() {
    scanf("%s %s", inOrder, preOrder);
    int n = strlen(inOrder);
    Node* root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}
