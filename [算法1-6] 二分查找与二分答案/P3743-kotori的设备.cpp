#include <iostream>
using namespace std;

const int MAXN = 200000;

int n;
double p, sum, a[MAXN], b[MAXN];

bool check(double x) {
    double q = p * x;
    sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * x <= b[i]) continue;
        sum += (a[i] * x - b[i]);
    }
    return sum <= q;
}

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p) {
        cout << -1 << endl;
        return 0;
    }
    double l = 0, r = 1e10;
    while (r - l > 0.00001){
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}
