#include <cstdio>
#include <algorithm>
using namespace std;

class BinaryIndexedTree {
    private:
        int* c;
        size_t len;

    public:
        BinaryIndexedTree(int n) : len(n) {
            c = (int*) malloc(n * sizeof(int));
        }
        void update(size_t pos) {
            while (pos < len) {
                c[pos] += 1;
                pos += pos & (-pos);
            }
        }
        int query(size_t pos) {
            int res = 0;
            while (pos > 0) {
                res += c[pos];
                pos -= pos & (-pos);
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
