#include <iostream>
using namespace std;

const int MAXM = 1e6 + 1;

int n, m, l, r, s[MAXM];
bool notPrime[MAXM];

void solve() {
    for (int i = 2; i <= m; i++) {
        if (notPrime[i]) {
            s[i] = s[i - 1];
        } else {
            s[i] = s[i - 1] + 1;
            for (int j = i << 1; j <= m; j += i) {
                notPrime[j] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    solve();
    while (n--) {
        cin >> l >> r;
        if (l < 1 || r > m) cout << "Crossing the line" << endl;
        else cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
