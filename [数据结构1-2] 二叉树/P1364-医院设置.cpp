#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

struct Node {
    int val, left, right;
};

int n, ans = INF;
vector<int> dis, size;
vector<Node> node;

void dfs(int root, int depth) {
    size[root] = node[root].val;
    if (node[root].left) {
        dfs(node[root].left, depth + 1);
        size[root] += size[node[root].left];
    }
    if (node[root].right) {
        dfs(node[root].right, depth + 1);
        size[root] += size[node[root].right];
    }
    dis[1] += node[root].val * depth;
}

void cog(int root) {
    if (node[root].left) {
        dis[node[root].left] = dis[root] + size[1] - 2 * size[node[root].left];
        cog(node[root].left); 
    }
    if (node[root].right) {
        dis[node[root].right] = dis[root] + size[1] - 2 * size[node[root].right];
        cog(node[root].right);
    }
    ans = min(ans, dis[root]);
}

int main() {
    scanf("%d", &n);
    node.resize(n + 1);
    dis.resize(n + 1);
    size.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &node[i].val, &node[i].left, &node[i].right);
    }
    dfs(1, 0);
    cog(1);
    printf("%d", ans);
    return 0;
}
