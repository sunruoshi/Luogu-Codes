#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int p = n + 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] != i) {
                p = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == p) reverse(a + p, a + i + 1);
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
