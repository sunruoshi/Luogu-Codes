#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int v, w;
    Edge(int _v) : v(_v), w(1) {}
};

int n, k, vt, d1, d2;
vector<int> depth, p;
vector<vector<Edge>> adj;
vector<bool> mark;

void dfs(int u, int fa) {
    p[u] = fa;
    if (depth[u] > depth[vt]) vt = u;
    for (auto edge : adj[u]) {
        int v = edge.v, w = edge.w;
        if (v != fa) {
            depth[v] = depth[u] + w;
            dfs(v, u);
        }
    }
}

void DP(int u, int fa) {
    for (auto edge : adj[u]) {
        int v = edge.v, w = edge.w;
        if (v != fa) {
            DP(v, u);
            d2 = max(d2, depth[u] + depth[v] + w);
            depth[u] = max(depth[u], depth[v] + w);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    adj.resize(n + 1);
    depth.resize(n + 1);
    p.resize(n + 1);
    mark.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(Edge(v));
        adj[v].push_back(Edge(u));
    }
    dfs(1, 0);
    depth[vt] = 0;
    dfs(vt, 0);
    d1 = depth[vt];
    if (k == 1) {
        printf("%d", 2 * (n - 1) - d1 + 1);
        return 0;
    }
    while (vt) {
        mark[vt] = 1;
        vt = p[vt];
    }
    for (int u = 1; u <= n; u++) {
        if (!mark[u]) continue;
        for (auto &edge : adj[u]) {
            if (mark[edge.v]) edge.w = -1;
        }
    }
    fill(depth.begin(), depth.end(), 0);
    DP(1, 0);
    printf("%d", 2 * n - d1 - d2);
    return 0;
}
