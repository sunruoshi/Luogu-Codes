#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a1, a2;
        cin >> a1 >> a2;
        a2 /= gcd(a1, a2);
        for (int i = 3; i <= n; i++) {
            int x;
            cin >> x;
            a2 /= gcd(a2, x);
        }
        cout << (a2 == 1 ? "Yes" : "No") << endl;
    }
    return 0;
}
