#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30001;

int n, fa[MAXN], dist[MAXN], num[MAXN];

int Find(int x) {
    if (x == fa[x]) return x;
    int fx = Find(fa[x]);
    dist[x] += dist[fa[x]];
    fa[x] = fx;
    return fx;
}

void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    dist[fx] += num[fy];
    num[fy] += num[fx];
    num[fx] = 0;
    fa[fx] = fy;
}

int main() {
    cin >> n;
    for (int i = 1; i <= MAXN; i++) {
        fa[i] = i;
        num[i] = 1;
    }
    while (n--) {
        char op;
        int i, j;
        cin >> op >> i >> j;
        if (op == 'M') Union(i, j);
        else {
            int fi = Find(i), fj = Find(j);
            if (fi != fj) cout << "-1" << endl;
            else cout << abs(dist[i] - dist[j]) - 1 << endl;
        }
    }
    return 0;
}

