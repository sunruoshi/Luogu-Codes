#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

struct Node {
    int left, right;
} node[MAXN];

int n, root = 1;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        node[i] = Node({0, 0});
    }
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (!node[u].left) node[u].left = v;
        else node[u].right = v;
    }
    return 0;
}
