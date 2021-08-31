#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans1, ans2 = 0x3f3f3f3f;
vector<int> dis, size;
vector<vector<int>> node;

void dfs(int u, int fa, int depth) {
    size[u] = 1;
    for (int v : node[u]) {
        if (v != fa) {
            dfs(v, u, depth + 1);
            size[u] += size[v]; 
        }
    }
    dis[1] += depth;
}

void cog(int u, int fa) {
    for (int v : node[u]) {
        if (v != fa) {
            dis[v] = dis[u] + size[1] - 2 * size[v];
            cog(v, u);
        }
    }
    if (dis[u] < ans2) {
        ans2 = dis[u];
        ans1 = u;
    } else if (dis[u] == ans2 && u < ans1) {
        ans1 = u;
    }
}

int main() {
    scanf("%d", &n);
    node.resize(n + 1);
    dis.resize(n + 1);
    size.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        node[u].push_back(v);
        node[v].push_back(u);
    }
    dfs(1, 0, 0);
    cog(1, 0);
    printf("%d %d", ans1, ans2);
    return 0;
}
