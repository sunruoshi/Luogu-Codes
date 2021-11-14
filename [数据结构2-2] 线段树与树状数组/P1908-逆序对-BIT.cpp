#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class BinaryIndexedTree {
    private:
        vector<T> c;

    public:
        BinaryIndexedTree(size_t n) { c.resize(n); }
        void update(size_t pos, T v);
        T query(size_t pos);
};

template <class T>
void BinaryIndexedTree<T>::update(size_t pos, T v) {
    while (pos < c.size()) {
        c[pos] += v;
        pos += pos & (-pos);
    }
}

template <class T>
T BinaryIndexedTree<T>::query(size_t pos) {
    T res = 0;
    while (pos > 0) {
        res += c[pos];
        pos -= pos & (-pos);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> nums(n + 1), temp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        temp[i] = nums[i];
    }
    sort(temp.begin() + 1, temp.end());
    for (int i = 1; i <= n; i++) {
        int &num = nums[i];
        num = lower_bound(temp.begin() + 1, temp.end(), num) - temp.begin();
    }
    BinaryIndexedTree<int> bit(n + 1);
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
        bit.update(nums[i], 1);
        ans += bit.query(nums[i] - 1);
    }
    cout << ans;
    return 0;
}
