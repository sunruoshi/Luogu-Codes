#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 5001
using namespace std;

int n, m, tag, maxSize, id;
int dfn[MAXN], low[MAXN], scc[MAXN], size[MAXN];
bool inStack[MAXN];
vector<int> adj[MAXN], stk;

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
            stk.pop_back();
            inStack[cur] = 0;
            scc[cur] = u;
            size[u]++;
            if (cur == u) break;
        }
        if (size[u] > maxSize) {
            maxSize = size[u];
            id = u;
        } else if (size[u] == maxSize && u < id) {
            id = u;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, opt;
        scanf("%d %d %d", &u, &v, &opt);
        adj[u].push_back(v);
        if (opt == 2) adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) tarjan(u);
    }
    printf("%d\n", maxSize);
    for (int u = 1; u <= n; u++) {
        if (scc[u] == id) printf("%d ", u);
    }
    return 0;
}
