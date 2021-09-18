#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    private:
        vector<int> fa;

    public:
        UnionFind(int n) {
            fa.resize(n + 1);
            for (int i = 1; i <= n; i++) {
                fa[i] = i;
            }
        }
        int Find(int x) {
            return x == fa[x] ? x : fa[x] = Find(fa[x]);
        }
        void Union(int x, int y) {
            fa[Find(x)] = Find(y);
        }
};

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    UnionFind uf(n << 1);
    while (m--) {
        char opt;
        int x, y;
        cin >> opt >> x >> y;
        if (opt == 'E') {
            uf.Union(x + n, y);
            uf.Union(y + n, x);
        } else {
            uf.Union(x, y);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (uf.Find(i) == i) cnt++;
    }
    cout << cnt;
    return 0;
}
