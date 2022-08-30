#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], tmp[n], cnt[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
        cnt[i] = 0;
    }
    sort(tmp, tmp + n);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(tmp, tmp + n, a[i]) - tmp;
    }
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i]) cout << tmp[i] << ' ' << cnt[i] << endl;
    }
    return 0;
}
