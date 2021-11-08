#include <cstdio>
#include <cstdlib>

class BinaryIndexedTree {
    private:
        int* c;
        size_t len;

    public:
        BinaryIndexedTree(int n) : c((int*) malloc(n * sizeof(int))), len(n) {}
        void update(size_t pos, int v);
        int query(size_t pos);
};

void BinaryIndexedTree::update(size_t pos, int v) {
    while (pos < len) {
        c[pos] += v;
        pos += pos & (-pos);
    }
}
int BinaryIndexedTree::query(size_t pos) {
    int res = 0;
    while (pos > 0) {
        res += c[pos];
        pos -= pos & (-pos);
    }
    return res;
}

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
