#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#define MAXN 100001
using namespace std;

int n, k, vt, depth[MAXN], maxDepth[MAXN], p[MAXN];
vector<vector<int>> adj;

void dfs1(int u, int fa) {
    p[u] = fa;
    if (depth[u] > depth[vt]) vt = u;
    for (int v : adj[u]) {
        if (v != fa) {
            depth[v] = depth[u] + 1;
            dfs1(v, u);
        }
    }
}

void dfs2(int u, int fa) {
    maxDepth[u] = depth[u];
    for (int v : adj[u]) {
        if (v != fa) {
            depth[v] = depth[u] + 1;
            dfs2(v, u);
            maxDepth[u] = max(maxDepth[u], maxDepth[v]);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    depth[vt] = 0;
    dfs1(vt, 0);
    int root = vt;
    for (int i = 1; i <= (1 + depth[vt]) >> 1; i++) {
        root = p[root];
    }
    depth[root] = 0;
    dfs2(root, 0);
    int ans[n + 1];
    for (int i = 1; i <= n; i++) {
        ans[i] = maxDepth[i] - depth[i];
    }
    sort(ans + 1, ans + n + 1, greater<int>());
    printf("%d", *max_element(ans + k + 1, ans + n + 1) + 1);
    return 0;
}
