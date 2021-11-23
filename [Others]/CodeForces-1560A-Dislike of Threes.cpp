#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 || i % 10 == 3) n++;
        }
        cout << n << endl;
    }
    return 0;
}
