#include <iostream>
#include <queue>
using namespace std;

struct Milk {
    int price, num;
    bool operator < (const Milk &a) const {
        return price > a.price;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<Milk> q;
    while (m--) {
        Milk x;
        cin >> x.price >> x.num;
        q.push(x);
    }
    int ans = 0;
    while (q.size()) {
        Milk x = q.top();
        q.pop();
        if (n >= x.num) {
            ans += x.num * x.price;
            n -= x.num;
        } else {
            ans += n * x.price;
            break;
        }
    }
    cout << ans;
    return 0;
}
