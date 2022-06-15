#include <iostream>
#include <cstring>
#include <string>
#include <regex>
using namespace std;

struct Node {
    string addr;
    int id;
} network[1001];

int n, p, id;

regex e("((\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){3}(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]):(\\d|[1-9]\\d{1,3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5])");

bool isConnected(string s) {
    for (int i = 1; i <= p; i++) {
        if (s == network[i].addr) {
            id = network[i].id;
            return 1;
        }
    }
    return 0;
}

int main() {
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string type, addr;
        cin >> type >> addr;
        if (!regex_match(addr, e)) {
            cout << "ERR" << endl;
            continue;
        }
        if (type == "Server") {
            if (isConnected(addr)) {
                cout << "FAIL" << endl;
            } else {
                Node t;
                t.addr = addr;
                t.id = i;
                network[++p] = t;
                cout << "OK" << endl;
            }
        } else {
            if (isConnected(addr)) {
                cout << id << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
