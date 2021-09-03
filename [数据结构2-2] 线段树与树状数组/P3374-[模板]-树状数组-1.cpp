#include <cstdio>
#include <vector>
#define lowbit(i) ((i) & (-i))
using namespace std;

class BinaryIndexedTree {
    private:
        vector<int> c;

    public:
        BinaryIndexedTree(int n) {
            c.resize(n);
        }
        void update(unsigned pos, int v) {
            while (pos < c.size()) {
                c[pos] += v;
                pos += lowbit(pos);
            }
        }
        int query(unsigned pos) {
            int res = 0;
            while (pos > 0) {
                res += c[pos];
                pos -= lowbit(pos);
            }
            return res;
        }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    BinaryIndexedTree bit(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        bit.update(i, x);
    }
    for (int i = 1; i <= m; i++) {
        int opt, x, y;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) bit.update(x, y);
        else printf("%d\n", bit.query(y) - bit.query(x - 1));
    }
    return 0;
}
