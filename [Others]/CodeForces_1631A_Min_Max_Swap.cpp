#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n], max1 = 0, max2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            max1 = max(max1, a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            max1 = max(max1, b[i]);
            max2 = max(max2, min(a[i], b[i]));
        }
        cout << max1 * max2 << endl;
    }
    return 0;
}
