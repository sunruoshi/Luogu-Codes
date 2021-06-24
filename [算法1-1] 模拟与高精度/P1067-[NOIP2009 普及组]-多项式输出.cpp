#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        int a;
        cin >> a;
        if (i == n) {
            if (a > 1 || a < -1) {
                cout << a << "x^" << i;
            } else if (a == 1) {
                cout << "x^" << i;
            } else if (a == -1) {
                cout << "-x^" << i;
            }
        } else if (i < n && i > 1) {
            if (a > 1) {
                cout << "+" << a << "x^" << i;
            } else if (a == 1) {
                cout << "+x^" << i;
            } else if (a == -1) {
                cout << "-x^" << i;
            } else if (a < -1) {
                cout << a << "x^" << i;
            }
        } else if (i == 1) {
            if (a > 1) {
                cout << "+" << a << "x";
            } else if (a == 1) {
                cout << "+x";
            } else if (a == -1) {
                cout << "-x";
            } else if (a < -1) {
                cout << a << "x";
            }
        } else if (i == 0) {
            if (a > 0) {
                cout << "+" << a;
            } else if (a < 0) {
                cout << a;
            }
        }
    }
    return 0;
}
