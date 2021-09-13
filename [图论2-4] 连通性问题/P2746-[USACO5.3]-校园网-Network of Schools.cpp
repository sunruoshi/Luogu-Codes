#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 101
using namespace std;

int n, tag, cnt, num1, num2;
int dfn[MAXN], low[MAXN], scc[MAXN], in[MAXN], out[MAXN];
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
        cnt++;
        while (stk.size()) {
            int cur = stk.back();
            scc[cur] = u;
            inStack[cur] = 0;
            stk.pop_back();
            if (cur == u) break;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int u = 1; u <= n; u++) {
        while (1) {
            int v;
            scanf("%d", &v);
            if (!v) break;
            adj[u].push_back(v);
        }
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) tarjan(u);
    }
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v]) {
                in[scc[v]]++;
                out[scc[u]]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (scc[i] == i && !in[i]) num1++;
        if (scc[i] == i && !out[i]) num2++;
    }
    if (cnt == 1) printf("1\n0");
    else printf("%d\n%d", num1, max(num1, num2));
    return 0;
}
