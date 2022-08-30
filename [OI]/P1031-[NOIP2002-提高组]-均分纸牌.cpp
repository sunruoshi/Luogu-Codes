#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sum /= n;
    for (int i = 0; i < n; i++) {
        a[i] -= sum;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            a[i + 1] += a[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
