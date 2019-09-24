#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005;

int n;

typedef pair<ll, ll> pii;

struct state {
	pii p1, p2;
}line[N];

void read () {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		line[i].p1 = make_pair(x1, y1);
		line[i].p2 = make_pair(x2, y2);
	}
}

bool inside (pii a, pii b, pii c) {
return (c.first >= min(a.first, b.first) && c.first <= max(a.first, b.first) &&
		c.second >= min(a.second, b.second) && c.second <= max(a.second, b.second));
}

int CrossProduct (pii a, pii b, pii c) {
	ll area = a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);

return (area >= 0 ? 1 : -1);
}

bool intersect (int i, int j) {
	int isCCW[4];

	isCCW[0] = CrossProduct(line[i].p1, line[i].p2, line[j].p1);
	isCCW[1] = CrossProduct(line[i].p1, line[i].p2, line[j].p2);
	isCCW[2] = CrossProduct(line[j].p1, line[j].p2, line[i].p1);
	isCCW[3] = CrossProduct(line[j].p1, line[j].p2, line[i].p2);

	if ((isCCW[0] != isCCW[1]) && (isCCW[2] != isCCW[3]))
		return true;
	
return false;
}

void solve () {
	int res = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			if (intersect(i, j)) {
				res ++;
			}
		}
	}

	printf("%d\n", res);
}

int main () {
	read ();
	solve ();

return 0;
}