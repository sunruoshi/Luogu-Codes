#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int v, w;
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

int n, s, vt, ans = 0x3f3f3f3f;
vector<int> depth, p;
vector<vector<Edge>> adj;
vector<bool> onD;

void dfs(int u, int fa) {
    p[u] = fa;
    if (depth[u] > depth[vt]) vt = u;
    for (auto edge : adj[u]) {
        int v = edge.v, w = edge.w;
        if (v != fa && !onD[v]) {
            depth[v] = depth[u] + w;
            dfs(v, u);
        }
    }
}

int main() {
    scanf("%d %d", &n, &s);
    adj.resize(n + 1);
    depth.resize(n + 1);
    p.resize(n + 1);
    onD.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }
    dfs(1, 0);
    depth[vt] = 0;
    dfs(vt, 0);
    for (int u = vt, v = vt; u > 0; u = p[u]) {
        while (depth[v] - depth[u] > s) v = p[v];
        ans = min(ans, max(depth[vt] - depth[v], depth[u]));
    }
    for (int u = vt; u > 0; u = p[u]) {
        onD[u] = 1;
    }
    for (int u = vt; u > 0; u = p[u]) {
        depth[u] = 0;
        dfs(u, p[u]);
    }
    printf("%d", max(ans, *max_element(depth.begin() + 1, depth.end())));
    return 0;
}
