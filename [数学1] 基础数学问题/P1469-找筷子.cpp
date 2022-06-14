#include <iostream>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
    return 0;
}
