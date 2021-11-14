#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BinaryIndexedTree {
    private:
        vector<int> c;

    public:
        BinaryIndexedTree(int n) { c.resize(n); }
        void update(size_t pos);
        int query(size_t pos);
};

void BinaryIndexedTree::update(size_t pos) {
    while (pos < c.size()) {
        c[pos] += 1;
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

const int MOD = 1e8 - 3;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        d[i] = i;
    }
    sort(c.begin() + 1, c.end(), [&](int i, int j) { return a[i] < a[j]; });
    sort(d.begin() + 1, d.end(), [&](int i, int j) { return b[i] < b[j]; });
    vector<int> q(n + 1);
    for (int i = 1; i <= n; i++) {
        q[c[i]] = d[i];
    }
    BinaryIndexedTree bit(n + 1);
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        bit.update(q[i]);
        ans = (ans + bit.query(q[i] - 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
