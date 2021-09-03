#include <cstdio>
#include <vector>
#include <algorithm>
#define lowbit(i) ((i) & (-i))
using namespace std;

class BinaryIndexedTree {
    private:
        vector<int> c;

    public:
        BinaryIndexedTree(int n) {
            c.resize(n);
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
};

int main() {
    int n;
    scanf("%d", &n);
    int nums[n], temp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        temp[i] = nums[i];
    }
    sort(temp, temp + n);
    for (int &num : nums) {
        num = lower_bound(temp, temp + n, num) - temp + 1;
    }
    BinaryIndexedTree bit(n + 1);
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        bit.update(nums[i]);
        ans += bit.query(nums[i] - 1);
    }
    printf("%lld", ans);
    return 0;
}
