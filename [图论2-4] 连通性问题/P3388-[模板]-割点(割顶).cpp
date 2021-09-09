#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num, ans;
vector<int> dfn, low;
vector<bool> res;
vector<vector<int>> adj;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++num;
    int child = 0;
    for (int v : adj[u]) {
        if (v == fa) continue;
        if (!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (u != fa && dfn[u] <= low[v] && !res[u]) {
                res[u] = 1;
                ans++;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (u == fa && child >= 2 && !res[u]) {
        res[u] = 1;
        ans++;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    dfn.resize(n + 1);
    low.resize(n + 1);
    res.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) {
            num = 0;
            tarjan(u, u);
        }
    }
    printf("%d\n", ans);
    for (int u = 1; u <= n; u++) {
        if (res[u]) printf("%d ", u);
    }
    return 0;
}
