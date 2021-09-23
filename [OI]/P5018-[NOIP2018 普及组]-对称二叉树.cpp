#include <cstdio>
#include <algorithm>
#define MAXN 1000001
using namespace std;

struct Node {
    int left, right, val, size;
} node[MAXN];

void dfs(int root) {
    node[root].size = 1;
    int left = node[root].left, right = node[root].right;
    if (left != -1) {
        dfs(left);
        node[root].size += node[left].size;
    }
    if (right != -1) {
        dfs(right);
        node[root].size += node[right].size;
    }
}

bool check(int u, int v) {
    if (u == -1 && v == -1) return 1;
    if (
            u != -1 && v != -1 && 
            node[u].val == node[v].val && 
            check(node[u].left, node[v].right) && 
            check(node[u].right, node[v].left)
       ) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].val);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &node[i].left, &node[i].right);
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (check(node[i].left, node[i].right)) ans = max(ans, node[i].size);
    }
    printf("%d", ans);
    return 0;
}
