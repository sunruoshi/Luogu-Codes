#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 2e5 + 1, INF = 0x3f3f3f3f;

int n, ans = INF, in[N];
vector<int> adj[N];

void dfs(int u, int s, int len) {
    in[u]--;
    for (int v : adj[u]) {
        if (v == s) {
            ans = min(ans, len);
            return;
        }
        dfs(v, s, len + 1);
    }
}

int main() {
    cin >> n;
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i]) dfs(i, i, 1);
    }
    cout << ans << endl;
    return 0;
}
