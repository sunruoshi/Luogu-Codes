#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 200001
using namespace std;

int n, tag, ans = 0x3f3f3f3f;
int dfn[MAXN], low[MAXN];
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
        int size = 0;
        while (stk.size()) {
            size++;
            int cur = stk.back();
            stk.pop_back();
            inStack[cur] = 0;
            if (cur == u) break;
        }
        if (size > 1) ans = min(ans, size);
    }
}

int main() {
    scanf("%d", &n);
    for (int u = 1; u <= n; u++) {
        int v;
        scanf("%d", &v);
        adj[u].push_back(v);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) tarjan(u);
    }
    printf("%d", ans);
    return 0;
}
