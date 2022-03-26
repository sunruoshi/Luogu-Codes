#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, a[3];
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[0] == 0 && a[1] == 0) {
            cout << 0 << endl;
        } else if (a[0] == 0) {
            if (a[1] == a[2]) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        } else {
            if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0] + a[1]) {
                cout << 2 << endl;
            } else {
                cout << 3 << endl;
            }
        }
    }
    return 0;
}
