#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 30001;

int n, fa[MAXN], dis[MAXN], size[MAXN];

int Find(int x) {
    if (x == fa[x]) return x;
    int fx = Find(fa[x]);
    dis[x] += dis[fa[x]];
    fa[x] = fx;
    return fx;
}

void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    dis[fx] += size[fy];
    size[fy] += size[fx];
    size[fx] = 0;
    fa[fx] = fy;
}

int main() {
    cin >> n;
    for (int i = 1; i <= MAXN; i++) {
        fa[i] = i;
        size[i] = 1;
    }
    while (n--) {
        char opt;
        int i, j;
        cin >> opt >> i >> j;
        if (opt == 'M') Union(i, j);
        else {
            int fi = Find(i), fj = Find(j);
            if (fi != fj) cout << "-1" << endl;
            else cout << abs(dis[i] - dis[j]) - 1 << endl;
        }
    }
    return 0;
}

