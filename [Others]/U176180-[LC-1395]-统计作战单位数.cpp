#include <cstdio>
#include <vector>
#include <algorithm>
#define lowbit(i) ((i) & (-i))
using namespace std;

struct Node {
    int val, pos;
    Node(int _val, int _pos) : val(_val), pos(_pos) {}
    bool operator < (const Node &a) const {
        return val < a.val;
    }
};

class BinaryIndexedTree {
    private:
        vector<int> c;

    public:
        BinaryIndexedTree(int n) {
            c.resize(n, 0);
        }
        void update(unsigned pos) {
            while (pos < c.size()) {
                c[pos] += 1;
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
        void clear() {
            fill(c.begin(), c.end(), 0);
        }
};

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    vector<int> nums(n);
    vector<Node> temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        temp.push_back(Node(nums[i], i));
    }
    sort(temp.begin(), temp.end());
    vector<int> Hash(n), iLess(n), iMore(n), kLess(n), kMore(n);
    for (int i = 0; i < n; i++) {
        Hash[temp[i].pos] = i + 1;
    }
    BinaryIndexedTree bit(n + 1);
    for (int i = 0; i < n; i++) {
        bit.update(Hash[i]);
        iLess[i] = bit.query(Hash[i] - 1);
        iMore[i] = bit.query(n) - bit.query(Hash[i]);
    }
    bit.clear();
    for (int i = n - 1; i >= 0; i--) {
        bit.update(Hash[i]);
        kLess[i] = bit.query(Hash[i] - 1);
        kMore[i] = bit.query(n) - bit.query(Hash[i]);
    }
    for (int i = 0; i < n; i++) {
        ans += iLess[i] * kMore[i] + iMore[i] * kLess[i];
    }
    printf("%d", ans);
    return 0;
}
