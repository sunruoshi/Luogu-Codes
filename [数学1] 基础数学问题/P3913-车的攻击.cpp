#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 1e6 + 2;

ll n, k, r, c, x[N], y[N];

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + k + 1);
    sort(y + 1, y + k + 1);
    for (int i = 1; i <= k; i++) {
        if (x[i] != x[i + 1]) r++;
        if (y[i] != y[i + 1]) c++;
    }
    cout << n * n - (n - r) * (n - c) << endl;
    return 0;
}
