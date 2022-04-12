#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int main() {
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = 2, b = n - 3;
        while (gcd(a, b) != 1) {
            a++;
            b--;
        }
        cout << a << ' ' << b << ' ' << 1 << endl; 
    }
    return 0;
}
