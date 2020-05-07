#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, m;
int par[N], height[N];

struct point {
	int x, y;
};

struct line {
	point p1, p2;
} A[N];

void read() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		A[i].p1 = {x1, y1};
		A[i].p2 = {x2, y2};

		if (A[i].p1.x > A[i].p2.x || (A[i].p1.x == A[i].p2.x && A[i].p1.y > A[i].p2.y))
			swap(A[i].p1, A[i].p2);
	}
}

int findSet(int pos) {
	if (par[pos] == pos)
		return pos;

return par[pos] = findSet(par[pos]);
}

bool sameSet(int x, int y) { return findSet(x) == findSet(y); }

void merge(int u, int v) {
	int x = findSet(u);
	int y = findSet(v);

	if (height[x] >= height[y])
		par[y] = x;
	else
		par[x] = y;

	if (height[x] == height[y])
		height[x] ++;
}

int crossProduct(point p, point q, point r) {
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0)
		return 0;

	return (val > 0) ? 1 : 2;
}

bool onSegment(point p, point q, point r) {
	return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

bool isIntersect(int i, int j) {
	int orientations[] = {
		crossProduct(A[i].p1, A[i].p2, A[j].p1),
		crossProduct(A[i].p1, A[i].p2, A[j].p2),
		crossProduct(A[j].p1, A[j].p2, A[i].p1),
		crossProduct(A[j].p1, A[j].p2, A[i].p2)
	};

	if (orientations[0] != orientations[1] && orientations[2] != orientations[3])
		return true;
	if (orientations[0] == 0 && onSegment(A[i].p1, A[j].p1, A[i].p2))
		return true;
	if (orientations[1] == 0 && onSegment(A[i].p1, A[j].p2, A[i].p2))
		return true;
	if (orientations[2] == 0 && onSegment(A[j].p1, A[i].p1, A[j].p2))
		return true;
	if (orientations[3] == 0 && onSegment(A[j].p1, A[i].p2, A[j].p2))
		return true;

	return false;
}

void solve() {
	for (int i = 0; i < n; i ++) {
		par[i] = i;
		height[i] = 0;
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (i == j)
				continue;

			if (isIntersect(i, j) && !sameSet(i, j))
				merge(i, j);
		}
	}

	while (m --) {
		int x, y;
		scanf("%d %d", &x, &y);

		printf("%s\n", sameSet(x - 1, y - 1) ? "YES" : "NO");
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		read();
		solve();
	}

return 0;
}