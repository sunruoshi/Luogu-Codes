#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    long long sum = 0, a[n + 1];
    cin >> a[1];
    if (a[1] > x) {
        sum += a[1] - x;
        a[1] = x;
    }
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        if (a[i] + a[i - 1] > x) {
            sum += a[i] + a[i - 1] - x;
            a[i] = x - a[i - 1];
        }
    }
    cout << sum;
    return 0;
}
