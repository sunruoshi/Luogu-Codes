#include <cstdio>
#include <algorithm>
using namespace std;

struct Coin {
	int weight;
	double value;
	double ratio;
};

bool cmp(Coin a, Coin b) {
	return a.ratio > b.ratio;
}

int main () {
	int n, t;
	double total = 0.0;
	scanf("%d %d", &n, &t);
	Coin coins[n];
	for (int i = 0; i < n; i++) {
		Coin c;
		scanf("%d %lf", &c.weight, &c.value);
		c.ratio = c.value / c.weight;
		coins[i] = c;
	}
	sort(coins, coins + n, cmp);
	for (int i = 0; i < n; i++) {
		if (t < coins[i].weight) {
			total += t * coins[i].ratio;
			break;
		}
		t -= coins[i].weight;
		total += coins[i].value;
	}
	printf("%.2lf", total);
	return 0;
}