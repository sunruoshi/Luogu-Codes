#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 10001
using namespace std;

int n, m, tag, ans;
int dfn[MAXN], low[MAXN], size[MAXN];
bool inStack[MAXN];
vector<int> stk, adj[MAXN];

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
            size[u]++;
            inStack[cur] = 0;
            stk.pop_back();
            if (cur == u) break;
        }
        if (size[u] > 1) ans++;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) tarjan(u);
    }
    printf("%d", ans);
    return 0;
}
