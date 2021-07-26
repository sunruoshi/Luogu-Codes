#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 101, INF = 0x3f3f3f;

struct Node {
    int val, left, right;
    Node() {}
    Node(int _val, int _left, int _right) {
        val = _val;
        left = _left;
        right = _right;
    }
} node[MAXN];

int n, ans = INF, dis[MAXN], size[MAXN];

void preTreat(int root, int depth) {
    size[root] = node[root].val;
    if (node[root].left) {
        preTreat(node[root].left, depth + 1);
        size[root] += size[node[root].left];
    }
    if (node[root].right) {
        preTreat(node[root].right, depth + 1);
        size[root] += size[node[root].right];
    }
    dis[1] += node[root].val * depth;
}

void findCog(int root) {
    if (node[root].left) {
        dis[node[root].left] = dis[root] + size[1] - 2 * size[node[root].left];
        findCog(node[root].left); 
    }
    if (node[root].right) {
        dis[node[root].right] = dis[root] + size[1] - 2 * size[node[root].right];
        findCog(node[root].right);
    }
    ans = min(ans, dis[root]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &node[i].val, &node[i].left, &node[i].right);
    }
    preTreat(1, 0);
    findCog(1);
    printf("%d", ans);
    return 0;
}
