#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Condition {
    int x, y, e;
};

class UnionFind {
    private:
        vector<int> fa;

    public:
        UnionFind(int n) {
            fa.resize(n << 1);
            for (int i = 0; i < n << 1; i++) {
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
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        UnionFind uf(n);
        vector<Condition> cons(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &cons[i].x, &cons[i].y, &cons[i].e);
            if (!mp.count(cons[i].x)) mp.emplace(cons[i].x, i);
            if (!mp.count(cons[i].y)) mp.emplace(cons[i].y, i + n);
        }
        sort(cons.begin(), cons.end(), [](Condition a, Condition b) { return a.e > b.e; });
        bool flag = 1;
        for (auto con : cons) {
            if (con.e) uf.Union(mp[con.x], mp[con.y]);
            else {
                if (uf.Find(mp[con.x]) == uf.Find(mp[con.y])) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
