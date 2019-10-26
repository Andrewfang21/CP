#include<bits/stdc++.h>
using namespace std;

const int N = 900;
const double eps = 10e-9;

int n, m;
int par[N], height[N];

double l, r;

struct state {
	int from ,to, a, b;
	double value;
}A[N];

bool compare(state lhs, state rhs) {
	return lhs.value < rhs.value;
}

int findSet(int pos) {
	return (pos == par[pos] ? pos : findSet(par[pos]));
}

bool sameSet(int u, int v) {return findSet(u) == findSet(v);}

void mergeSet(int u, int v) {
	int x, y;
	x = findSet(u);
	y = findSet(v);

	if (height[x] >= height[y])
		par[y] = par[x];
	else
		par[x] = par[y];

	if (height[x] == height[y])
		height[x] ++;
}

double getCost(double pos) {
	for (int i = 0; i <= 140; i ++)
		par[i] = i;

	for (int i = 1; i <= m; i ++)
		A[i].value = A[i].a * pos + A[i].b;

	sort(A + 1, A + m + 1, compare);

	double cost = 0.0;
	for (int i = 1; i <= m; i ++) {
		int u, v;
		u = A[i].from;
		v = A[i].to;

		if (!sameSet(u, v)) {
			mergeSet(u, v);
			cost += A[i].value;
		}
	}

return cost;
}

void read() {
	cin >> n >> m;
	cin >> l >> r;

	for (int i = 1; i <= m; i ++)
		cin >> A[i].from >> A[i].to >> A[i].a >> A[i].b;
}

void solve() {
	double mid, x, y;
	for (int i = 1; i <= 40; i ++) {
		mid = (l + r) / 2.0;

		x = getCost(mid - eps);
		y = getCost(mid + eps);

		if (x - y > eps)
			r = mid;
		else
			l = mid;
	}

	cout << setprecision(3) << fixed << mid << " " << x << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;

	while(tc --) {
		read();
		solve();
	}
return 0;
}