#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int d[26], n = a.size(), m = b.size();
        memset(d, 0, sizeof(d));
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (d[a[i] - 'A']) continue;
            if (a[i] == b[j]) j--;
            else d[a[i] - 'A'] = 1;
        }
        if (j < 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
