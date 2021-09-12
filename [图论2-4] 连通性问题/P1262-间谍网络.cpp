#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 3001
#define INF 0x3f3f3f3f
using namespace std;

int n, p, r, tag, ans;
int dfn[MAXN], low[MAXN], scc[MAXN], in[MAXN];
vector<int> adj[MAXN], stk, weight, cost;
bool inStack[MAXN];

void tarjan(int u) {
    dfn[u] = low[u] = ++tag;
    stk.push_back(u);
    inStack[u] = 1;
    for (int v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        while (stk.size()) {
            int cur = stk.back();
            scc[cur] = u;
            cost[u] = min(cost[u], weight[cur]);
            stk.pop_back();
            inStack[cur] = 0;
            if (cur == u) break;
        }
    }
}

int main() {
    scanf("%d %d", &n, &p);
    weight.resize(n + 1, INF);
    cost.resize(n + 1, INF);
    for (int i = 1; i <= p; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        weight[u] = w;
    }
    scanf("%d", &r);
    for (int i = 1; i <= r; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u] && weight[u] != INF) tarjan(u);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) {
            printf("NO\n%d", u);
            return 0;
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v]) in[scc[v]]++;
        }
    }
    for (int u = 1; u <= n; u++) {
        if (scc[u] == u && !in[u]) ans += cost[u];
    }
    printf("YES\n%d", ans);
    return 0;
}
