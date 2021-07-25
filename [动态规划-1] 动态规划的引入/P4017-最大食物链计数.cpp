#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

const int MAXN = 5001, MOD = 80112002;

int n, m, ans, in[MAXN], out[MAXN], dp[MAXN];
vector<int> adj[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        in[v]++;
        out[u]++;
        adj[u].push_back(v);
    }
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            dp[i] = 1;
            q.push_back(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            dp[v] += dp[u];
            dp[v] %= MOD;
            in[v]--;
            if (!in[v]) {
                if (out[v] == 0) {
                    ans += dp[v];
                    ans %= MOD;
                }
                q.push_back(v);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
