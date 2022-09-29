#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 1, INF = 0x3f3f3f3f;

int n, id, ans = INF, dfn[N], low[N];
bool inStack[N];
vector<int> adj[N], stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++id;
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
    cin >> n;
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        adj[u].push_back(v);
    }
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) tarjan(u);
    }
    cout << ans << endl;
    return 0;
}
