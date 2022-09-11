#include <iostream>
#include <string>
using namespace std;

const int N = 1e5;

struct Toy {
    int face;
    string name;
} t[N];

int main() {
    int n, m, pos = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i].face >> t[i].name;
    }
    for (int i = 0; i < m; i++) {
        int dir, cnt;
        cin >> dir >> cnt;
        pos = dir ^ t[pos].face ? (pos + cnt) % n : (pos + n - cnt) % n;
    }
    cout << t[pos].name;
    return 0;
}
