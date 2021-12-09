#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int q[n], size[n], cnt = 0;
    for (int i = 0; i < n; i++) {
        int p = lower_bound(q, q + cnt, a[i]) - q;
        while (p < cnt && q[p + 1] == a[i]) p++;
        if (p == cnt || q[p] != a[i]) {
            q[cnt] = a[i] + 1;
            size[cnt++] = 1;
        } else {
            q[p]++;
            size[p]++;
        }
    }
    cout << *min_element(size, size + cnt);
    return 0;
}
