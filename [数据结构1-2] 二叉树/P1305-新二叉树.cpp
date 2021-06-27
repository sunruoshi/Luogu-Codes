#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;

int n, root;

struct Node {
    int left, right;
} node[MAXN];

void preOrder(int root) {
    if (root == -1) return;
    printf("%c", root + 'a');
    preOrder(node[root].left);
    preOrder(node[root].right);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (i == 0) root = s[0] - 'a';
        node[s[0] - 'a'].left = s[1] == '*' ? -1 : s[1] - 'a';
        node[s[0] - 'a'].right = s[2] == '*' ? -1 : s[2] - 'a';
    }
    preOrder(root);
    return 0;
}
