#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6;

long long a[MAXN], s[MAXN], MAX;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i < n - k + 1; i++) {
        MAX = max(MAX, s[i + k - 1] - s[i - 1]);
    }
    cout << s[n - 1] - MAX;
    return 0;
}
