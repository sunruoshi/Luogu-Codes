#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAXN = 1001;

struct Node {
    int u, level;
    Node(int _u, int _level) {
        u = _u;
        level = _level;
    }
};

int n, m, ans, s[MAXN], in[MAXN];
vector<int> adj[MAXN];
bool stoped[MAXN], visited[MAXN][MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        memset(stoped, 0, sizeof(stoped));
        int t;
        scanf("%d", &t);
        for (int j = 1; j <= t; j++) {
            scanf("%d", &s[j]);
            stoped[s[j]] = 1;
        }
        for (int j = s[1]; j <= s[t]; j++) {
            if (stoped[j]) continue;
            for (int k = 1; k <= t; k++) {
                if (visited[s[k]][j]) continue;
                in[j]++;
                visited[s[k]][j] = 1;
                adj[s[k]].push_back(j);
            }
        }
    }
    deque<Node> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) q.push_back(Node(i, 1));
    }
    while (q.size()) {
        Node cur = q.front();
        q.pop_front();
        for (int i = 0; i < adj[cur.u].size(); i++) {
            int v = adj[cur.u][i];
            in[v]--;
            if (!in[v]) {
                q.push_back(Node(v, cur.level + 1));
                ans = max(ans, cur.level + 1);
            }
        }
    }
    printf("%d", ans);
    return 0;
}
