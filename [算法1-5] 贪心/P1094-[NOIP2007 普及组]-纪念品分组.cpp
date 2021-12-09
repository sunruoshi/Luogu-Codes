#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0, l = 0, r = n - 1;
    while (l <= r) {
        while (a[l] + a[r] > w) {
            r--;
            ans++;
        }
        ans++;
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
