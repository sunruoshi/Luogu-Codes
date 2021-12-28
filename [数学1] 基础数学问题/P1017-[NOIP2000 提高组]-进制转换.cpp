#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string ans = "";
    int n, r;
    cin >> n >> r;
    cout << n << '=';
    while (n) {
        int c = n % r;
        n /= r;
        if (c < 0) {
            c -= r;
            n++;
        }
        if (c >= 10) {
            ans += char(c - 10 + 'A');
        } else {
            ans += char(c + '0');
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "(base" << r << ")";
    return 0;
}
