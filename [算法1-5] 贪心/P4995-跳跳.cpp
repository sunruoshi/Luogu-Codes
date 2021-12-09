#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    sort(a + 1, a + n + 1);
    long long ans = 0;
    int cnt = 0, l = 0, r = n;
    auto square = [&](int x, int y) { return (x - y) * (x - y); };
    while (cnt < n) {
        ans += square(a[l], a[r]);
        cnt++;
        if (cnt & 1) l++;
        else r--;
    }
    cout << ans;
    return 0;
}
