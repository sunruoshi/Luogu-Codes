#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct E {
    int v, w;
};

int n, p, c[101], u[101], in[101], out[101];
vector<E> adj[101];

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
    }
    for (int i = 1; i <= p; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(E({y, w}));
        in[y]++;
        out[x]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i] && c[i] > 0) q.push(i);
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto e : adj[x]) {
            int y = e.v, w = e.w;
            c[y] += w * c[x];
            in[y]--;
            if (!in[y]) {
                c[y] -= u[y];
                if (c[y] > 0) q.push(y);
            }
        }
    }
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        if (!out[i] && c[i] > 0) {
            flag = 1;
            cout << i << ' ' << c[i] << endl;
        }
    }
    if (!flag) cout << "NULL" << endl;
    return 0;
}
