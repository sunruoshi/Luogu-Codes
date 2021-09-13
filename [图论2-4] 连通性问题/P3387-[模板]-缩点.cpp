#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 10001
using namespace std;

int n, m, tag;
int dfn[MAXN], low[MAXN], scc[MAXN], w[MAXN], dp[MAXN];
bool inStack[MAXN];
vector<int> stk, adj[MAXN], dag[MAXN];

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
            inStack[cur] = 0;
            stk.pop_back();
            if (cur == u) break;
            w[u] += w[cur];
        }
    }
}

int DP(int u) {
    if (dp[u]) return dp[u];
    for (int v : dag[u]) {
        dp[u] = max(dp[u], DP(v));
    }
    dp[u] += w[u];
    return dp[u];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) tarjan(u);
    }
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v]) dag[scc[u]].push_back(scc[v]);
        }
    }
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        ans = max(ans, DP(u));
    }
    printf("%d", ans);
    return 0;
}
