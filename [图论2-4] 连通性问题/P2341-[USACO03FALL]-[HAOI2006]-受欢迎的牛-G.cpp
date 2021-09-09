#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 10001
using namespace std;

int n, m, tag, pos, idx;
int dfn[MAXN], low[MAXN], scc[MAXN], size[MAXN], stk[MAXN], out[MAXN];
bool inStack[MAXN];
vector<int> adj[MAXN];

void tarjan(int u) {
    dfn[u] = low[u] = ++tag;
    stk[++pos] = u;
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
        idx++;
        while (stk[pos] != u) {
            scc[stk[pos]] = idx;
            size[idx]++;
            inStack[stk[pos]] = 0;
            pos--;
        }
        scc[stk[pos]] = idx;
        size[idx]++;
        inStack[stk[pos]] = 0;
        pos--;
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
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v]) out[scc[u]]++;
        }
    }
    int id = 0;
    for (int i = 1; i <= idx; i++) {
        if (!out[i]) {
            if (id) {
                printf("0");
                return 0;
            }
            id = i;
        }
    }
    printf("%d", size[id]);
    return 0;
}
