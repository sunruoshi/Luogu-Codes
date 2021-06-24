#include <iostream>
using namespace std;

int A, B;

void judge(int a, int b) {
    if (a == 0) {
        if (b == 2 || b == 3) A++;
        else if (b != a) B++;
    } else if (a == 1) {
        if (b == 0 || b == 3) A++;
        else if (b != a) B++;
    } else if (a == 2) {
        if (b == 1 || b == 4) A++;
        else if (b != a) B++;
    } else if (a == 3) {
        if (b == 2 || b == 4) A++;
        else if (b != a) B++;
    } else if (a == 4) {
        if (b == 0 || b == 1) A++;
        else if (b != a) B++;
    }
}

int main() {
    int n, na, nb;
    cin >> n >> na >> nb;
    int a[na], b[nb];
    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        judge(a[i % na], b[i % nb]);
    }
    cout << A << " " << B;
    return 0;
}
