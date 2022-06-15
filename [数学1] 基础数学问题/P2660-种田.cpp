#include <iostream>
using namespace std;

typedef long long ll;

ll x, y, ans;

int main() {
    cin >> x >> y;
    while (x && y) {
        swap(x, y);
        ans += 4 * y * (x / y);
        x %= y;
    }
    cout << ans << endl;
    return 0;
}
