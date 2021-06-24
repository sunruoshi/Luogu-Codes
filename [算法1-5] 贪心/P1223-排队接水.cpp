#include <cstdio>
#include <algorithm>
using namespace std;

struct Person {
	int pos;
	double time;
};

bool cmp(Person p1, Person p2) {
	return p1.time < p2.time;
}

int main() {
	int n;
	double sum = 0.0, prev = 0.0;
	scanf("%d", &n);
	Person people[n];
	for (int i = 0; i < n; i++) {
		Person p;
		p.pos = i + 1;
		scanf("%lf", &p.time);
		people[i] = p;
	}
	sort(people, people + n, cmp);
	printf("%d ", people[0].pos);
	for (int i = 1; i < n; i++) {
		prev += people[i - 1].time;
		sum += prev;
		printf("%d ", people[i].pos);
	}
	printf("\n%.2lf", sum / n);
	return 0;
}