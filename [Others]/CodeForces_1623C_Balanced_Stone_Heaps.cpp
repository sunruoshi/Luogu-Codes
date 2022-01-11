#include <iostream>
#include <vector>
using namespace std;

int t, n;

bool check(int x, vector<int> &a) {
    vector<int> b = a;
    for (int i = n; i >= 3; i--) {
        if (b[i] < x) return false;
        int d = min(b[i] - x, a[i]) / 3;
        b[i - 1] += d;
        b[i - 2] += 2 * d;
    }
    return min(b[1], b[2]) >= x; 
};

int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int l = 1, r = 1e9, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid, a)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
