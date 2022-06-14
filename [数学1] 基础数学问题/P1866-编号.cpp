#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= (a[i] - i);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
