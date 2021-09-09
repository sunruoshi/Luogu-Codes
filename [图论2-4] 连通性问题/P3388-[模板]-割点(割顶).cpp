#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 20001
using namespace std;

int n, m, tag, ans;
int dfn[MAXN], low[MAXN];
bool res[MAXN];
vector<int> adj[MAXN];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tag;
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
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) {
            tag = 0;
            tarjan(u, u);
        }
    }
    printf("%d\n", ans);
    for (int u = 1; u <= n; u++) {
        if (res[u]) printf("%d ", u);
    }
    return 0;
}
