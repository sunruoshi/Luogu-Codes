#include <iostream>
#include <string>
#include <cstring>
#include <deque>
#include <map>
using namespace std;

const int MAXN = 15;

struct Node {
    string str;
    int step;
    Node(string _str, int _step) {
        str = _str;
        step = _step;
    }
};

string a, b, orginal[MAXN], translated[MAXN];
int n, ans;
map<string, int> ma;

string translate(const string &str, int i, int j) {
    string ans = "";
    if (i + orginal[j].size() > str.size()) return ans;
    for (int k = 0; k < orginal[j].size(); k++) {
        if (str[i + k] != orginal[j][k]) return ans;
    }
    ans = str.substr(0, i);
    ans += translated[j];
    ans += str.substr(i + orginal[j].size());
    return ans;
}

int main(){
    cin >> a >> b;
    while (cin >> orginal[n] >> translated[n]) n++;
    deque<Node> q;
    q.push_back(Node(a, 0));
    while (q.size()) {
        Node cur = q.front();
        q.pop_front();
        if (ma.count(cur.str) == 1) continue;
        if (cur.str == b){
            ans = cur.step;
            break;
        }
        ma[cur.str] = 1;
        for (int i = 0; i < cur.str.size(); i++) {
            for (int j = 0; j < n; j++) {
                string temp = translate(cur.str, i, j);
                if (temp != "") q.push_back(Node(temp, cur.step + 1));
            }
        }
    }
    if (ans > 10 || ans == 0) cout << "NO ANSWER!" << endl;
    else cout << ans << endl;
    return 0;
}
